#pragma once
#include <string>
#include <vector>
#include "Doctor.h"
#include "Bed.h"

class Department {
private:
    std::string name;
    std::vector<Doctor> doctors;
    std::vector<Bed> beds;

public:
    Department(std::string name);

    std::string getName() const;
    const std::vector<Doctor>& getDoctors() const;
    const std::vector<Bed>& getBeds() const;

    void addDoctor(const Doctor& doctor);
    void addBed(const Bed& bed);
    
    // New: Allocate a free bed to a patient
    bool allocateBed(int patientId);

    void displayInfo() const;
};