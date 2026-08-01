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
    Doctor(); // Default constructor
    Doctor(int id, std::string name, std::string specialization);

    int getId() const;
    std::string getName() const;
    std::string getSpecialization() const;
    bool getIsAvailable() const;

    void setIsAvailable(bool status);
    void displayInfo() const;
};