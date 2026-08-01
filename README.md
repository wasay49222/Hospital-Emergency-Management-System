# 🏥 Hospital Emergency Management System

A robust, full-stack C++ application simulating a hospital's emergency and general operations. This project demonstrates practical applications of advanced Data Structures and Algorithms (DSA) combined with a modern **JavaScript Web Frontend** and a **C++ REST API Backend**.

## 🚀 Features & DSA Concepts Applied

- **Triage & Waiting Management**: 
  - *Priority Queue (Max-Heap)*: Ensures critical patients (Severity 1) are treated before normal cases.
  - *Standard Queue (FIFO)*: Manages the waiting line for non-emergency patients.
- **Medical Record Management**: 
  - *Binary Search Tree (BST)*: Stores patient records sorted by ID for $O(\log n)$ search and retrieval.
  - *Hash Map (`std::unordered_map`)*: Provides $O(1)$ constant-time lookup for active patient records.
- **Resource Allocation**: 
  - *Arrays & Vectors*: Manages fixed-size resources like hospital beds and department lists.
- **Ambulance & Staff Routing**: 
  - *Graph (Adjacency List) + BFS*: Calculates the shortest path between hospital departments.
- **Data Persistence & Undo**: 
  - *File Handling (CSV)*: Automatically saves and loads patient records, ensuring data survives server restarts.
  - *Stack*: Tracks recent actions to allow an "Undo" feature.
- **Full-Stack Integration**: 
  - *C++ REST API*: Built with `cpp-httplib` to serve JSON endpoints.
  - *Vanilla JS Frontend*: A clean, responsive UI that communicates with the C++ backend via `fetch()`.

## 📂 Project Structure

```text
├── server.cpp                # C++ Web Server & REST API endpoints
├── index.html                # JavaScript Frontend UI
├── httplib.h                 # Single-header HTTP library
├── json.hpp                  # Single-header JSON library
├── main.cpp                  # Original CLI entry point (kept for reference)
├── Hospital.h / .cpp         # Core manager class orchestrating all DSA systems
├── PriorityQueueManager.h/.cpp # Max-Heap implementation for triage
├── PatientQueue.h / .cpp     # FIFO queue for normal patients
├── PatientRecordBST.h / .cpp # Binary Search Tree for sorted records
├── HospitalGraph.h / .cpp    # Graph structure and BFS routing algorithms
├── FileHandler.h / .cpp      # File I/O operations for data persistence
└── [Entity Files]            # Patient, Doctor, Bed, Department classes

🛠️ How to Compile and Run
Prerequisites
A C++ compiler (e.g., g++ via MinGW/MSYS2)
A modern web browser
1. Compile the Web Server
Open your terminal in the project directory and run:

g++ server.cpp Patient.cpp Doctor.cpp Bed.cpp Department.cpp PatientQueue.cpp PriorityQueueManager.cpp PatientRecordBST.cpp HospitalGraph.cpp Hospital.cpp FileHandler.cpp -o server.exe -lws2_32

(Note: -lws2_32 is required on Windows to link the Winsock networking library).
2. Start the Server

.\server.exe

3. Open the Frontend
Open your web browser and navigate to:
👉 http://localhost:8080
👨‍💻 Author
Wasay
