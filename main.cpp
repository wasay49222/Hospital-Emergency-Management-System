#include <iostream>
#include <string>
#include <limits>
#include "Hospital.h"

// Helper function to safely get integer input (prevents crashes on bad input)
int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            // Clear the newline character left in the buffer so getline works next
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear(); // Reset the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the bad text
        }
    }
}

// Helper function to safely get string input (handles spaces like "John Doe")
std::string getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

void displayMenu() {
    std::cout << "\n===============================================\n";
    std::cout << "  HOSPITAL EMERGENCY MANAGEMENT SYSTEM\n";
    std::cout << "===============================================\n";
    std::cout << "1. Admit Patient\n";
    std::cout << "2. Treat Next Patient\n";
    std::cout << "3. Allocate Bed\n";
    std::cout << "4. Find Ambulance Route\n";
    std::cout << "5. Undo Last Admission\n";
    std::cout << "6. Display All Records\n";
    std::cout << "7. Save Data to File\n";
    std::cout << "8. Load Data from File\n";
    std::cout << "0. Exit\n";
    std::cout << "===============================================\n";
}

int main() {
    Hospital cityHospital;

    // Auto-load data on startup if it exists
    cityHospital.loadData("hospital_data.csv");

    while (true) {
        displayMenu();
        int choice = getIntInput("Enter your choice: ");

        if (choice == 0) {
            std::cout << "Saving data before exit...\n";
            cityHospital.saveData("hospital_data.csv");
            std::cout << "Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1: {
                int id = getIntInput("Enter Patient ID: ");
                std::string name = getStringInput("Enter Name: ");
                int age = getIntInput("Enter Age: ");
                int severity = getIntInput("Enter Severity (1=Critical, 5=Normal): ");
                cityHospital.admitPatient(Patient(id, name, age, severity));
                break;
            }
            case 2:
                cityHospital.treatNextPatient();
                break;
            case 3: {
                int id = getIntInput("Enter Patient ID: ");
                std::string dept = getStringInput("Enter Department Name (e.g., Emergency Room, ICU): ");
                cityHospital.allocateBed(id, dept);
                break;
            }
            case 4: {
                std::string start = getStringInput("Enter Start Location: ");
                std::string end = getStringInput("Enter Destination: ");
                cityHospital.findRoute(start, end);
                break;
            }
            case 5:
                cityHospital.undoLastAction();
                break;
            case 6:
                cityHospital.displayAllRecords();
                break;
            case 7:
                cityHospital.saveData("hospital_data.csv");
                break;
            case 8:
                cityHospital.loadData("hospital_data.csv");
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}