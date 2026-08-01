#include "PatientQueue.h"
#include <iostream>
#include <stdexcept>

void PatientQueue::addPatient(const Patient& patient) {
    normalQueue.push(patient);
}

Patient PatientQueue::removePatient() {
    if (isEmpty()) {
        throw std::runtime_error("Normal Queue is empty!");
    }
    Patient p = normalQueue.front();
    normalQueue.pop();
    return p;
}

bool PatientQueue::isEmpty() const {
    return normalQueue.empty();
}

void PatientQueue::displayQueue() const {
    if (isEmpty()) {
        std::cout << "Normal Queue is empty.\n";
        return;
    }
    std::cout << "--- Normal Patient Queue (FIFO) ---\n";
    // std::queue doesn't allow direct iteration, so we copy it to display
    std::queue<Patient> temp = normalQueue;
    while (!temp.empty()) {
        temp.front().displayInfo();
        temp.pop();
    }
    std::cout << "---------------------------------\n";
}

int PatientQueue::getSize() const {
    return normalQueue.size();
}