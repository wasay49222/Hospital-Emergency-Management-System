#include "PriorityQueueManager.h"
#include <iostream>
#include <stdexcept>

void PriorityQueueManager::addPatient(const Patient& patient) {
    emergencyQueue.push(patient);
}

Patient PriorityQueueManager::removePatient() {
    if (isEmpty()) {
        throw std::runtime_error("Emergency Queue is empty!");
    }
    Patient p = emergencyQueue.top();
    emergencyQueue.pop();
    return p;
}

bool PriorityQueueManager::isEmpty() const {
    return emergencyQueue.empty();
}

void PriorityQueueManager::displayQueue() const {
    if (isEmpty()) {
        std::cout << "Emergency Queue is empty.\n";
        return;
    }
    std::cout << "--- Emergency Patient Queue (Sorted by Severity) ---\n";
    // Copy to display without destroying the original queue
    std::priority_queue<Patient, std::vector<Patient>, CompareSeverity> temp = emergencyQueue;
    while (!temp.empty()) {
        temp.top().displayInfo();
        temp.pop();
    }
    std::cout << "----------------------------------------------------\n";
}

int PriorityQueueManager::getSize() const {
    return emergencyQueue.size();
}