#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

int main() {
    std::ifstream file("incidents.csv");
    if (!file.is_open()) {
        std::cerr << "❌ Fehler beim Öffnen der Datei 'incidents.csv'\n";
        return 1;
    }

    std::string line;
    std::getline(file, line); // Header überspringen

    std::map<std::string, int> teamCounter;
    std::map<std::string, int> priorityCounter;
    int total = 0;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        int col = 0;
        std::string team, priority;

        while (std::getline(ss, field, ',')) {
            if (col == 2) priority = field;
            if (col == 3) team = field;
            col++;
        }

        if (!team.empty()) {
            teamCounter[team]++;
            priorityCounter[priority]++;
            total++;
        }
    }

    std::cout << "📊 Santander Incident Analyzer (C++)\n";
    std::cout << "Total Incidents: " << total << "\n\n";

    std::cout << "--- Incidents per Team ---\n";
    for (std::map<std::string, int>::const_iterator it = teamCounter.begin(); it != teamCounter.end(); ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }

    std::cout << "\n--- Incidents by Priority ---\n";
    for (std::map<std::string, int>::const_iterator it = priorityCounter.begin(); it != priorityCounter.end(); ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }

    return 0;
}
