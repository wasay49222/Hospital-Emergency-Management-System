#include "Bed.h"
#include <string> // Added this to fix the std::to_string error

Bed::Bed() : bedId(0), isOccupied(false), patientId(0) {}

Bed::Bed(int bedId) : bedId(bedId), isOccupied(false), patientId(0) {}

int Bed::getBedId() const { return bedId; }
bool Bed::getIsOccupied() const { return isOccupied; }
int Bed::getPatientId() const { return patientId; }

void Bed::occupy(int patientId) {
    this->isOccupied = true;
    this->patientId = patientId;
}

void Bed::free() {
    this->isOccupied = false;
    this->patientId = 0;
}

void Bed::displayInfo() const {
    std::cout << "[Bed] ID: " << bedId << " | Status: " 
              << (isOccupied ? "Occupied by Patient " + std::to_string(patientId) : "Free") << "\n";
}