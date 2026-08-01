#pragma once
#include <string>
#include <vector>
#include "Patient.h"

class FileHandler {
public:
    static void savePatients(const std::vector<Patient>& patients, const std::string& filename);
    static std::vector<Patient> loadPatients(const std::string& filename);
};