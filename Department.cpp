#include "Department.h"
#include <iostream>

Department::Department(std::string name) : name(name) {}

std::string Department::getName() const { return name; }
const std::vector<Doctor>& Department::getDoctors() const { return doctors; }
const std::vector<Bed>& Department::getBeds() const { return beds; }

void Department::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
}

void Department::addBed(const Bed& bed) {
    beds.push_back(bed);
}

void Department::displayInfo() const {
    std::cout << "\n--- Department: " << name << " ---\n";
    std::cout << "Doctors (" << doctors.size() << "):\n";
    for (const auto& doc : doctors) {
        doc.displayInfo();
    }
    
    std::cout << "Beds (" << beds.size() << "):\n";
    for (const auto& bed : beds) {
        bed.displayInfo();
    }
    std::cout << "------------------------\n";
}