#pragma once
#include <iostream>

class Bed {
private:
    int bedId;
    bool isOccupied;
    int patientId; // 0 if empty

public:
    Bed(); // Default constructor
    Bed(int bedId);

    int getBedId() const;
    bool getIsOccupied() const;
    int getPatientId() const;

    void occupy(int patientId);
    void free();
    void displayInfo() const;
};