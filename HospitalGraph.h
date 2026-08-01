#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

class HospitalGraph {
private:
    // Adjacency list: Maps a department name to a list of connected departments
    std::unordered_map<std::string, std::vector<std::string>> adjList;

public:
    void addDepartment(const std::string& dept);
    void addCorridor(const std::string& dept1, const std::string& dept2); // Creates a two-way path
    void findShortestPath(const std::string& start, const std::string& end) const; // Uses BFS
};