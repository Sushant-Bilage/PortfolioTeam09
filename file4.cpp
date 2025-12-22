#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/* ===============================
   GRAPH – Waste Collection Network
   =============================== */
vector< vector<int> > graph;

/* ===============================
   HASH TABLE – Waste Categories
   =============================== */
map<int, string> wasteCategory;

/* ===============================
   PRIORITY QUEUE – Waste Priority
   =============================== */
priority_queue<int> wastePriority;

/* ===============================
   ADD WASTE CATEGORY
   =============================== */
void addWasteCategory() {
    int id;
    string type;

    cout << "Enter waste ID: ";
    cin >> id;

    cout << "Enter waste type (single word): ";
    cin >> type;

    wasteCategory[id] = type;
}

/* ===============================
   DISPLAY WASTE
   =============================== */
void displayWaste() {
    if (wasteCategory.empty()) {
        cout << "No waste data available.\n";
        return;
    }

    cout << "Waste Categories:\n";
    map<int, string>::iterator it;
    for (it = wasteCategory.begin(); it != wasteCategory.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
}

/* ===============================
   ADD PRIORITY
   =============================== */
void addPriority() {
    int p;
    cout << "Enter waste priority: ";
    cin >> p;

    wastePriority.push(p);
    cout << "Priority added.\n";
}

/* ===============================
   SORT WASTE (INTROSORT)
   =============================== */
void sortWaste() {
    if (wasteCategory.empty()) {
        cout << "No waste categories to sort.\n";
        return;
    }

    vector<string> items;
    map<int, string>::iterator it;

    for (it = wasteCategory.begin(); it != wasteCategory.end(); ++it) {
        items.push_back(it->second);
    }

    sort(items.begin(), items.end());   // Introsort

    cout << "Sorted Waste Categories (Introsort):\n";
    for (int i = 0; i < (int)items.size(); i++) {
        cout << items[i] << endl;
    }
}

/* ===============================
   MAIN FUNCTION
   =============================== */
int main() {
    int choice;

    do {
        cout << "\n--- Intelligent Waste Classification System ---\n";
        cout << "1. Add Waste Category\n";
        cout << "2. Display Waste Categories\n";
        cout << "3. Add Waste Priority\n";
        cout << "4. Sort Waste Categories (Introsort)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addWasteCategory(); break;
            case 2: displayWaste(); break;
            case 3: addPriority(); break;
            case 4: sortWaste(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
