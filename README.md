# 🏥 Hospital Emergency Management System

A robust, object-oriented C++ application simulating a hospital's emergency and general operations. This project demonstrates practical applications of advanced Data Structures and Algorithms (DSA) to solve real-world resource management, triage, and routing problems.

## 🚀 Features & DSA Concepts Applied

- **Triage & Waiting Management**: 
  - *Priority Queue (Max-Heap)*: Ensures critical patients (Severity 1) are treated before normal cases.
  - *Standard Queue (FIFO)*: Manages the waiting line for non-emergency patients.
- **Medical Record Management**: 
  - *Binary Search Tree (BST)*: Stores patient records sorted by ID for fast search and retrieval.
  - *Hash Map (`std::unordered_map`)*: Provides constant-time lookup for active patient records.
- **Resource Allocation**: 
  - *Arrays & Vectors*: Manages fixed-size resources like hospital beds and department lists.
- **Ambulance & Staff Routing**: 
  - *Graph (Adjacency List) + BFS*: Calculates the shortest path between hospital departments.
- **Data Persistence**: 
  - *File Handling*: Saves and loads patient records to/from disk.

## 📂 Project Structure

```text
├── main.cpp                  # Program entry point & CLI menu
├── Patient.h / .cpp          # Patient entity
├── Doctor.h / .cpp           # Doctor entity
├── Bed.h / .cpp              # Bed resource entity
├── Department.h / .cpp       # Department entity
├── Hospital.h / .cpp         # Core manager class
├── PriorityQueueManager.h/.cpp # Max-Heap implementation for triage
├── PatientQueue.h / .cpp     # FIFO queue for normal patients
├── PatientRecordBST.h / .cpp # Binary Search Tree for sorted records
├── HospitalGraph.h / .cpp    # Graph structure and BFS routing
└── FileHandler.h / .cpp      # File I/O operations

🛠️ How to Compile and Run
Compilation

g++ main.cpp Patient.cpp Doctor.cpp Bed.cpp Department.cpp PriorityQueueManager.cpp PatientQueue.cpp PatientRecordBST.cpp HospitalGraph.cpp FileHandler.cpp Hospital.cpp -o hospital.exe

Execution

.\hospital.exe

👨‍💻 Author
Wasay