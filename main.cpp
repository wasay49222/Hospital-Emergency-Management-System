#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Bed.h"
#include "Department.h"
#include "PatientQueue.h"
#include "PriorityQueueManager.h"

int main() {
    std::cout << "=== Hospital Emergency Management System - Level 2 Test ===\n\n";

    // 1. Create patients with different severities (1 = Critical, 5 = Minor)
    Patient p1(101, "John Doe", 45, 4);    // Severity 4
    Patient p2(102, "Jane Smith", 30, 1);  // Severity 1 (Critical!)
    Patient p3(103, "Bob Johnson", 50, 3); // Severity 3
    Patient p4(104, "Alice Brown", 25, 5); // Severity 5

    // 2. Test Normal Patient Queue (FIFO)
    PatientQueue normalQueue;
    normalQueue.addPatient(p1);
    normalQueue.addPatient(p4);
    
    std::cout << "Adding John (Severity 4) and Alice (Severity 5) to Normal Queue:\n";
    normalQueue.displayQueue();

    // 3. Test Emergency Priority Queue (Max-Heap based on urgency)
    PriorityQueueManager emergencyQueue;
    emergencyQueue.addPatient(p1); 
    emergencyQueue.addPatient(p2); // Critical patient added in the middle
    emergencyQueue.addPatient(p3);
    emergencyQueue.addPatient(p4);

    std::cout << "\nAdding ALL patients to Emergency Queue:\n";
    emergencyQueue.displayQueue();

    // 4. Simulate Triage: Treat the most critical patient first
    std::cout << "\n--- Simulating Triage ---\n";
    if (!emergencyQueue.isEmpty()) {
        Patient nextPatient = emergencyQueue.removePatient();
        std::cout << "Treating most critical patient: ";
        nextPatient.displayInfo();
    }

    std::cout << "\nEmergency Queue after treating one patient:\n";
    emergencyQueue.displayQueue();

    std::cout << "\n=== Level 2 Setup Successful! ===\n";
    return 0;
}