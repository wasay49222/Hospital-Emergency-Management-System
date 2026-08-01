#include "FileHandler.h"
#include <fstream>
#include <iostream>

void FileHandler::savePatients(const std::vector<Patient>& patients, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }
    for (const auto& p : patients) {
        // Save as CSV: id,name,age,severity,status
        file << p.getId() << "," << p.getName() << "," << p.getAge() << "," 
             << p.getSeverityLevel() << "," << p.getStatus() << "\n";
    }
    file.close();
    std::cout << "Data successfully saved to " << filename << "\n";
}

std::vector<Patient> FileHandler::loadPatients(const std::string& filename) {
    std::vector<Patient> patients;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "No existing data file found. Starting fresh.\n";
        return patients;
    }
    std::string line;
    while (std::getline(file, line)) {
        // Simple CSV parsing
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);
        size_t pos4 = line.find(',', pos3 + 1);

        if (pos1 != std::string::npos && pos2 != std::string::npos && pos3 != std::string::npos && pos4 != std::string::npos) {
            int id = std::stoi(line.substr(0, pos1));
            std::string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            int age = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
            int severity = std::stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
            std::string status = line.substr(pos4 + 1);

            Patient p(id, name, age, severity);
            p.setStatus(status);
            patients.push_back(p);
        }
    }
    file.close();
    std::cout << "Loaded " << patients.size() << " patients from " << filename << "\n";
    return patients;
}