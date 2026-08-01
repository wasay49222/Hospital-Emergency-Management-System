#pragma once
#include <queue>
#include <vector>
#include "Patient.h"

class PriorityQueueManager {
private:
    // Custom comparator for Max-Heap: Lower severity number = Higher Priority (e.g., 1 is critical)
    struct CompareSeverity {
        bool operator()(const Patient& a, const Patient& b) {
            // Return true if 'a' has LOWER priority than 'b'
            return a.getSeverityLevel() > b.getSeverityLevel(); 
        }
    };

    std::priority_queue<Patient, std::vector<Patient>, CompareSeverity> emergencyQueue;

public:
    void addPatient(const Patient& patient);
    Patient removePatient();
    bool isEmpty() const;
    void displayQueue() const;
    int getSize() const;
};