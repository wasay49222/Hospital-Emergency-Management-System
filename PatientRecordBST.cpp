#include "PatientRecordBST.h"
#include <iostream>

PatientRecordBST::PatientRecordBST() : root(nullptr) {}

PatientRecordBST::~PatientRecordBST() {
    clearTree(root);
}

void PatientRecordBST::clearTree(BSTNode* node) {
    if (node != nullptr) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

void PatientRecordBST::clear() {
    clearTree(root);
    root = nullptr;
}

void PatientRecordBST::insertHelper(BSTNode*& node, const Patient& patient) {
    if (node == nullptr) {
        node = new BSTNode(patient);
        return;
    }
    if (patient.getId() < node->patient.getId()) {
        insertHelper(node->left, patient);
    } else {
        insertHelper(node->right, patient);
    }
}

void PatientRecordBST::insertPatient(const Patient& patient) {
    insertHelper(root, patient);
}

Patient* PatientRecordBST::searchHelper(BSTNode* node, int id) const {
    if (node == nullptr) return nullptr; 
    if (node->patient.getId() == id) return &(node->patient); 
    
    if (id < node->patient.getId()) {
        return searchHelper(node->left, id);
    } else {
        return searchHelper(node->right, id);
    }
}

Patient* PatientRecordBST::searchPatient(int id) const {
    return searchHelper(root, id);
}

void PatientRecordBST::inorderHelper(BSTNode* node) const {
    if (node != nullptr) {
        inorderHelper(node->left);
        node->patient.displayInfo();
        inorderHelper(node->right);
    }
}

void PatientRecordBST::displayAllRecords() const {
    std::cout << "--- All Patient Records (Sorted by ID) ---\n";
    inorderHelper(root);
    std::cout << "------------------------------------------\n";
}