#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include "Patient.h"
#include "Doctor.h"
#include "Bed.h"
#include "Department.h"
#include "PatientQueue.h"
#include "PriorityQueueManager.h"
#include "PatientRecordBST.h"
#include "HospitalGraph.h"
#include "FileHandler.h"

class Hospital {
private:
    PatientQueue normalQueue;
    PriorityQueueManager emergencyQueue;
    std::unordered_map<int, Patient> patientRecords; 
    PatientRecordBST patientTree;                    
    HospitalGraph hospitalMap;
    std::vector<Department> departments;
    
    std::stack<int> actionStack; // Tracks recent admissions for the Undo feature
    void rebuildBST();           // Helper to rebuild the tree after an undo/load

public:
    std::vector<Patient> getAllPatients() const; // NEW: For the web server
    Hospital();
    
    // Setup
    void setupDepartments();
    void setupGraph();

    // Core Workflow
    void admitPatient(const Patient& patient);
    void treatNextPatient();
    void allocateBed(int patientId, const std::string& deptName);
    void findRoute(const std::string& start, const std::string& end);
    
    // Level 5 Features
    void undoLastAction();
    void saveData(const std::string& filename);
    void loadData(const std::string& filename);
    
    // Utilities
    void displayAllRecords() const;
};