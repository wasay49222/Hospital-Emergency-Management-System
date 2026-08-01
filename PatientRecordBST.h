#pragma once
#include "Patient.h"

// A single node in our Binary Search Tree
struct BSTNode {
    Patient patient;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Patient p) : patient(p), left(nullptr), right(nullptr) {}
};

class PatientRecordBST {
private:
    BSTNode* root;
    
    // Helper functions for recursion
    void insertHelper(BSTNode*& node, const Patient& patient);
    Patient* searchHelper(BSTNode* node, int id) const;
    void inorderHelper(BSTNode* node) const;
    void clearTree(BSTNode* node);

public:
    PatientRecordBST();
    ~PatientRecordBST(); // Cleans up memory when program ends
    
    void insertPatient(const Patient& patient);
    Patient* searchPatient(int id) const; 
    void displayAllRecords() const;
    void clear(); // Clears the tree so we can rebuild it after an undo or load
};