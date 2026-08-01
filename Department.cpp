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

bool Department::allocateBed(int patientId) {
    for (auto& bed : beds) {
        if (!bed.getIsOccupied()) {
            bed.occupy(patientId);
            std::cout << "  -> SUCCESS: Bed " << bed.getBedId() << " allocated to Patient " << patientId << ".\n";
            return true;
        }
    }
    std::cout << "  -> FAILED: No available beds in " << name << ".\n";
    return false;
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