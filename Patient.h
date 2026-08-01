#pragma once
#include <string>
#include <iostream>

class Patient {
private:
    int id;
    std::string name;
    int age;
    int severityLevel; // 1 = critical, 5 = normal
    std::string status; // "waiting", "treated"

public:
    Patient(); // Default constructor (Fixes the unordered_map error)
    Patient(int id, std::string name, int age, int severityLevel);
    
    // Getters
    int getId() const;
    std::string getName() const;
    int getAge() const;
    int getSeverityLevel() const;
    std::string getStatus() const;

    // Setters
    void setStatus(std::string status);

    // Utility
    void displayInfo() const;
};