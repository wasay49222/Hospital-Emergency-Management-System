#pragma once
#include <queue>
#include "Patient.h"

class PatientQueue {
private:
    std::queue<Patient> normalQueue;

public:
    void addPatient(const Patient& patient);
    Patient removePatient();
    bool isEmpty() const;
    void displayQueue() const;
    int getSize() const;
};