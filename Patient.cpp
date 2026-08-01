#include "Patient.h"

Patient::Patient(int id, std::string name, int age, int severityLevel) 
    : id(id), name(name), age(age), severityLevel(severityLevel), status("waiting") {}

int Patient::getId() const { return id; }
std::string Patient::getName() const { return name; }
int Patient::getAge() const { return age; }
int Patient::getSeverityLevel() const { return severityLevel; }
std::string Patient::getStatus() const { return status; }

void Patient::setStatus(std::string status) { this->status = status; }

void Patient::displayInfo() const {
    std::cout << "[Patient] ID: " << id << " | Name: " << name 
              << " | Age: " << age << " | Severity: " << severityLevel 
              << " | Status: " << status << "\n";
}