#include "httplib.h"
#include "json.hpp"
#include "Hospital.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <signal.h>

using json = nlohmann::json;

// Initialize our C++ Hospital system
Hospital cityHospital;
const std::string DATA_FILE = "hospital_data.csv";

// Global pointer to server for signal handling
httplib::Server* globalServer = nullptr;

// Signal handler to save data on Ctrl+C
void signalHandler(int signum) {
    std::cout << "\n\nInterrupt signal (" << signum << ") received.\n";
    std::cout << "Saving data before shutdown...\n";
    cityHospital.saveData(DATA_FILE);
    std::cout << "Data saved successfully. Goodbye!\n";
    if (globalServer) {
        globalServer->stop();
    }
    exit(signum);
}

// Helper function to load file content
std::string loadFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    // Register signal handler for Ctrl+C
    signal(SIGINT, signalHandler);
    
    // Load existing data on startup
    std::cout << "Loading existing patient data...\n";
    cityHospital.loadData(DATA_FILE);
    
    // Set global server pointer for signal handler
    globalServer = new httplib::Server();
    httplib::Server& svr = *globalServer;

    // Enable CORS so the JavaScript frontend is allowed to talk to this server
    svr.set_default_headers({
        {"Access-Control-Allow-Origin", "*"},
        {"Access-Control-Allow-Methods", "GET, POST, OPTIONS"},
        {"Access-Control-Allow-Headers", "Content-Type"}
    });

    // 1. GET / -> Serve the index.html file
    svr.Get("/", [&](const httplib::Request& req, httplib::Response& res) {
        std::string html = loadFile("index.html");
        if (html.empty()) {
            res.status = 404;
            res.set_content("index.html not found", "text/plain");
        } else {
            res.set_content(html, "text/html");
        }
    });

    // 2. GET /patients -> Returns all patients as a JSON array
    svr.Get("/patients", [&](const httplib::Request& req, httplib::Response& res) {
        auto patients = cityHospital.getAllPatients();
        json j = json::array();
        for (const auto& p : patients) {
            j.push_back({
                {"id", p.getId()},
                {"name", p.getName()},
                {"age", p.getAge()},
                {"severity", p.getSeverityLevel()},
                {"status", p.getStatus()}
            });
        }
        res.set_content(j.dump(), "application/json");
    });

    // 3. POST /admit -> Adds a new patient
    svr.Post("/admit", [&](const httplib::Request& req, httplib::Response& res) {
        try {
            auto body = json::parse(req.body);
            Patient p(body["id"], body["name"], body["age"], body["severity"]);
            cityHospital.admitPatient(p);
            cityHospital.saveData(DATA_FILE); // Auto-save after admitting
            res.set_content("{\"status\": \"success\"}", "application/json");
        } catch (...) {
            res.status = 400;
            res.set_content("{\"status\": \"error\", \"message\": \"Invalid JSON\"}", "application/json");
        }
    });

    // 4. POST /treat -> Treats the next patient in queue
    svr.Post("/treat", [&](const httplib::Request& req, httplib::Response& res) {
        cityHospital.treatNextPatient();
        cityHospital.saveData(DATA_FILE); // Auto-save after treating
        res.set_content("{\"status\": \"success\"}", "application/json");
    });

    // 5. POST /undo -> Undoes the last admission
    svr.Post("/undo", [&](const httplib::Request& req, httplib::Response& res) {
        cityHospital.undoLastAction();
        cityHospital.saveData(DATA_FILE); // Auto-save after undo
        res.set_content("{\"status\": \"success\"}", "application/json");
    });

    std::cout << "========================================\n";
    std::cout << "  C++ Hospital Server Running!\n";
    std::cout << "  Open http://localhost:8080 in your browser\n";
    std::cout << "  Data will be saved to: " << DATA_FILE << "\n";
    std::cout << "  Press Ctrl+C to stop (data will be saved)\n";
    std::cout << "========================================\n";
    
    // Start the server on port 8080
    svr.listen("0.0.0.0", 8080);
    
    delete globalServer;
    return 0;
}