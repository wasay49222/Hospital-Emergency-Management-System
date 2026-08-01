#include "Doctor.h"

Doctor::Doctor(int id, std::string name, std::string specialization) 
    : id(id), name(name), specialization(specialization), isAvailable(true) {}

int Doctor::getId() const { return id; }
std::string Doctor::getName() const { return name; }
std::string Doctor::getSpecialization() const { return specialization; }
bool Doctor::getIsAvailable() const { return isAvailable; }

void Doctor::setIsAvailable(bool status) { this->isAvailable = status; }

void Doctor::displayInfo() const {
    std::cout << "[Doctor] ID: " << id << " | Name: " << name 
              << " | Spec: " << specialization << " | Available: " 
              << (isAvailable ? "Yes" : "No") << "\n";
}