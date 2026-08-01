#include "Hospital.h"
#include <iostream>
#include <algorithm> // Added this to fix the std::sort error

Hospital::Hospital() {
    setupDepartments();
    setupGraph();
}

void Hospital::setupDepartments() {
    Department er("Emergency Room");
    er.addDoctor(Doctor(1, "Dr. House", "Diagnostics"));
    er.addBed(Bed(101));
    er.addBed(Bed(102));
    departments.push_back(er);

    Department icu("ICU");
    icu.addDoctor(Doctor(2, "Dr. Grey", "Surgery"));
    icu.addBed(Bed(201));
    icu.addBed(Bed(202));
    departments.push_back(icu);
}

void Hospital::setupGraph() {
    hospitalMap.addDepartment("Emergency Entrance");
    hospitalMap.addDepartment("Emergency Room");
    hospitalMap.addDepartment("ICU");
    hospitalMap.addDepartment("Surgery");
    
    hospitalMap.addCorridor("Emergency Entrance", "Emergency Room");
    hospitalMap.addCorridor("Emergency Room", "ICU");
    hospitalMap.addCorridor("Emergency Room", "Surgery");
    hospitalMap.addCorridor("ICU", "Surgery");
}

void Hospital::admitPatient(const Patient& patient) {
    std::cout << "\n[1. Admitting Patient] ";
    patient.displayInfo();
    
    if (patient.getSeverityLevel() <= 2) {
        emergencyQueue.addPatient(patient);
        std::cout << "   -> Added to EMERGENCY Priority Queue.\n";
    } else {
        normalQueue.addPatient(patient);
        std::cout << "   -> Added to NORMAL Waiting Queue.\n";
    }
    
    patientRecords[patient.getId()] = patient;
    patientTree.insertPatient(patient);
    actionStack.push(patient.getId()); // Track for Undo
}

void Hospital::treatNextPatient() {
    std::cout << "\n[2. Treating Next Patient]\n";
    
    if (!emergencyQueue.isEmpty()) {
        Patient p = emergencyQueue.removePatient();
        std::cout << "   -> Treating EMERGENCY patient: ";
        p.displayInfo();
        p.setStatus("treated");
        patientRecords[p.getId()] = p; 
    } 
    else if (!normalQueue.isEmpty()) {
        Patient p = normalQueue.removePatient();
        std::cout << "   -> Treating NORMAL patient: ";
        p.displayInfo();
        p.setStatus("treated");
        patientRecords[p.getId()] = p; 
    } 
    else {
        std::cout << "   -> No patients waiting to be treated.\n";
    }
}

void Hospital::allocateBed(int patientId, const std::string& deptName) {
    std::cout << "\n[4. Allocating Bed for Patient ID: " << patientId << " in " << deptName << "]\n";
    
    if (patientRecords.find(patientId) == patientRecords.end()) {
        std::cout << "   -> ERROR: Patient ID " << patientId << " not found in records.\n";
        return;
    }
    
    for (auto& dept : departments) {
        if (dept.getName() == deptName) {
            dept.allocateBed(patientId);
            return;
        }
    }
    std::cout << "   -> ERROR: Department '" << deptName << "' not found.\n";
}

void Hospital::findRoute(const std::string& start, const std::string& end) {
    std::cout << "\n[5. Ambulance Routing Request]\n";
    hospitalMap.findShortestPath(start, end);
}

void Hospital::displayAllRecords() const {
    std::cout << "\n[3. All Patient Records (Stored in BST & Hash Map)]\n";
    patientTree.displayAllRecords();
}

// --- LEVEL 5 & WEB SERVER IMPLEMENTATIONS ---

void Hospital::rebuildBST() {
    patientTree.clear();
    for (const auto& pair : patientRecords) {
        patientTree.insertPatient(pair.second);
    }
}

void Hospital::undoLastAction() {
    if (actionStack.empty()) {
        std::cout << "\n[Undo] Nothing to undo.\n";
        return;
    }
    int lastId = actionStack.top();
    actionStack.pop();
    
    if (patientRecords.find(lastId) != patientRecords.end()) {
        patientRecords.erase(lastId);
        rebuildBST(); 
        std::cout << "\n[Undo] Successful: Patient ID " << lastId << " admission reversed.\n";
    } else {
        std::cout << "\n[Undo] Failed: Patient record not found.\n";
    }
}

void Hospital::saveData(const std::string& filename) {
    std::vector<Patient> allPatients;
    for (const auto& pair : patientRecords) {
        allPatients.push_back(pair.second);
    }
    FileHandler::savePatients(allPatients, filename);
}

void Hospital::loadData(const std::string& filename) {
    // Clear existing data to prevent duplicates if loaded multiple times
    patientRecords.clear();
    patientTree.clear();
    while(!normalQueue.isEmpty()) normalQueue.removePatient();
    while(!emergencyQueue.isEmpty()) emergencyQueue.removePatient();

    std::vector<Patient> loadedPatients = FileHandler::loadPatients(filename);
    for (const auto& p : loadedPatients) {
        patientRecords[p.getId()] = p;
        patientTree.insertPatient(p);
        if (p.getSeverityLevel() <= 2) {
            emergencyQueue.addPatient(p);
        } else {
            normalQueue.addPatient(p);
        }
    }
    if (!loadedPatients.empty()) {
        std::cout << "Data loaded successfully into the active system.\n";
    }
}

// --- NEW: Helper for the Web Server ---
std::vector<Patient> Hospital::getAllPatients() const {
    std::vector<Patient> patients;
    for (const auto& pair : patientRecords) {
        patients.push_back(pair.second);
    }
    // Sort by ID so the frontend displays them neatly
    std::sort(patients.begin(), patients.end(), [](const Patient& a, const Patient& b) {
        return a.getId() < b.getId();
    });
    return patients;
}