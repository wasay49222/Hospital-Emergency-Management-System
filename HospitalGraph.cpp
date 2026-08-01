#include "HospitalGraph.h"

void HospitalGraph::addDepartment(const std::string& dept) {
    if (adjList.find(dept) == adjList.end()) {
        adjList[dept] = std::vector<std::string>();
    }
}

void HospitalGraph::addCorridor(const std::string& dept1, const std::string& dept2) {
    addDepartment(dept1); // Ensure both exist
    addDepartment(dept2);
    adjList[dept1].push_back(dept2);
    adjList[dept2].push_back(dept1); // Two-way corridor
}

void HospitalGraph::findShortestPath(const std::string& start, const std::string& end) const {
    if (adjList.find(start) == adjList.end() || adjList.find(end) == adjList.end()) {
        std::cout << "Error: One or both departments do not exist.\n";
        return;
    }

    std::queue<std::string> q;
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::string> parent; // To reconstruct the path

    q.push(start);
    visited[start] = true;

    bool found = false;

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        if (current == end) {
            found = true;
            break;
        }

        for (const std::string& neighbor : adjList.at(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if (found) {
        std::vector<std::string> path;
        std::string curr = end;
        while (curr != start) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(start);

        std::cout << "Shortest Path from " << start << " to " << end << ":\n";
        for (int i = path.size() - 1; i >= 0; --i) {
            std::cout << path[i] << (i > 0 ? " -> " : "\n");
        }
    } else {
        std::cout << "No path found between " << start << " and " << end << ".\n";
    }
}