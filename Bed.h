#pragma once
#include <iostream>

class Bed {
private:
    int bedId;
    bool isOccupied;
    int patientId; // 0 if empty

public:
    Bed(int bedId);

    // Getters
    int getBedId() const;
    bool getIsOccupied() const;
    int getPatientId() const;

    // Actions
    void occupy(int patientId);
    void free();

    // Utility
    void displayInfo() const;
};