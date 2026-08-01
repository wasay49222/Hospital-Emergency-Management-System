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

    // Getters
    std::string getName() const;
    const std::vector<Doctor>& getDoctors() const;
    const std::vector<Bed>& getBeds() const;

    // Actions
    void addDoctor(const Doctor& doctor);
    void addBed(const Bed& bed);

    // Utility
    void displayInfo() const;
};