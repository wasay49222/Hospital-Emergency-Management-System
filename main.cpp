#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Bed.h"
#include "Department.h"

int main() {
    std::cout << "=== Hospital Emergency Management System - Level 1 Test ===\n\n";

    // 1. Test Patient
    Patient p1(101, "John Doe", 45, 1); // Severity 1 (Critical)
    Patient p2(102, "Jane Smith", 30, 4); // Severity 4 (Normal)
    p1.displayInfo();
    p2.displayInfo();

    // 2. Test Doctor
    Doctor d1(1, "Dr. House", "Diagnostics");
    Doctor d2(2, "Dr. Grey", "Surgery");
    d1.displayInfo();
    d2.displayInfo(); // FIXED: Changed from displayIsAvailable() to displayInfo()
    
    // 3. Test Bed
    Bed b1(10);
    Bed b2(11);
    b1.occupy(101); // Patient 101 takes bed 10
    b1.displayInfo();
    b2.displayInfo();

    // 4. Test Department
    Department emergency("Emergency Room");
    emergency.addDoctor(d1);
    emergency.addDoctor(d2);
    emergency.addBed(b1);
    emergency.addBed(b2);
    
    emergency.displayInfo();

    std::cout << "\n=== Level 1 Setup Successful! ===\n";
    return 0;
}