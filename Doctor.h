#pragma once
#include <string>
#include <iostream>

class Doctor {
private:
    int id;
    std::string name;
    std::string specialization;
    bool isAvailable;

public:
    Doctor(int id, std::string name, std::string specialization);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getSpecialization() const;
    bool getIsAvailable() const;

    // Setters
    void setIsAvailable(bool status);

    // Utility
    void displayInfo() const;
};