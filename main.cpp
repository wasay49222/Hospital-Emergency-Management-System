#include <iostream>
#include "Patient.h"
#include "PatientQueue.h"
#include "PriorityQueueManager.h"
#include "PatientRecordBST.h"
#include "HospitalGraph.h"

int main() {
    std::cout << "=== Hospital Emergency Management System - Level 3 Test ===\n\n";

    // --- PART 1: Test Binary Search Tree (BST) ---
    std::cout << "--- 1. Testing Patient Record BST ---\n";
    PatientRecordBST records;
    
    Patient p1(105, "Charlie", 40, 2);
    Patient p2(101, "Alice", 30, 4);
    Patient p3(109, "Bob", 55, 1);
    
    // Insert in random order; BST will sort them by ID automatically
    records.insertPatient(p1);
    records.insertPatient(p2);
    records.insertPatient(p3);
    
    records.displayAllRecords();

    // Search for a patient
    int searchId = 101;
    Patient* found = records.searchPatient(searchId);
    if (found) {
        std::cout << "Search Successful! Found: ";
        found->displayInfo();
        // We can even update the patient directly through the pointer
        found->setStatus("treated");
        std::cout << "(Status updated to 'treated')\n";
    } else {
        std::cout << "Patient with ID " << searchId << " not found.\n";
    }

    // --- PART 2: Test Hospital Graph (BFS Routing) ---
    std::cout << "\n--- 2. Testing Hospital Graph Routing (BFS) ---\n";
    HospitalGraph hospitalMap;
    
    // Add departments
    hospitalMap.addDepartment("Emergency Entrance");
    hospitalMap.addDepartment("Triage");
    hospitalMap.addDepartment("ICU");
    hospitalMap.addDepartment("Surgery");
    hospitalMap.addDepartment("Radiology");

    // Add corridors (connections)
    hospitalMap.addCorridor("Emergency Entrance", "Triage");
    hospitalMap.addCorridor("Triage", "ICU");
    hospitalMap.addCorridor("Triage", "Radiology");
    hospitalMap.addCorridor("Radiology", "Surgery");
    hospitalMap.addCorridor("ICU", "Surgery"); // Direct path

    // Find shortest path
    std::cout << "\nRouting an ambulance from 'Emergency Entrance' to 'Surgery':\n";
    hospitalMap.findShortestPath("Emergency Entrance", "Surgery");

    std::cout << "\n=== Level 3 Setup Successful! ===\n";
    return 0;
}