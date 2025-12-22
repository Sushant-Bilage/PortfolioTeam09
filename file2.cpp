#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/* ==================================================
   MAP: Transport Classification (Energy Consumption)
   ================================================== */
map<string, int> transportEnergy;

/* ==================================================
   QUEUE: Transport Scheduling
   ================================================== */
queue<string> transportQueue;

/* ==================================================
   OPTION 1: Add Transport
   Purpose: Store transport type and energy usage
   ================================================== */
void addTransport() {
    string name;
    int energy;

    cout << "Enter transport name: ";
    cin >> name;
    cout << "Enter energy consumption (units): ";
    cin >> energy;

    transportEnergy[name] = energy;
    cout << "Transport added successfully.\n";
}

/* ==================================================
   OPTION 2: Display Transport Classification
   ================================================== */
void displayTransport() {
    if (transportEnergy.empty()) {
        cout << "No transport data available.\n";
        return;
    }

    cout << "\nTransport Classification:\n";
    for (auto it = transportEnergy.begin(); it != transportEnergy.end(); ++it) {
        cout << it->first << " -> " << it->second << " units\n";
    }
}

/* ==================================================
   OPTION 3: Greedy Algorithm
   Purpose: Select minimum energy vehicle
   ================================================== */
void greedySelection() {
    if (transportEnergy.empty()) {
        cout << "No transport data available.\n";
        return;
    }

    auto best = min_element(
        transportEnergy.begin(),
        transportEnergy.end(),
        [](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second < b.second;
        }
    );

    cout << "Most energy-efficient transport: "
         << best->first << " (" << best->second << " units)\n";
}

/* ==================================================
   OPTION 4: Queue Scheduling
   ================================================== */
void enqueueTransport() {
    string name;
    cout << "Enter transport name to schedule: ";
    cin >> name;

    transportQueue.push(name);
    cout << "Transport scheduled successfully.\n";
}

void showQueue() {
    if (transportQueue.empty()) {
        cout << "No scheduled transports.\n";
        return;
    }

    queue<string> temp = transportQueue;
    cout << "Transport Schedule:\n";
    while (!temp.empty()) {
        cout << temp.front() << " -> ";
        temp.pop();
    }
    cout << "END\n";
}

/* ==================================================
   OPTION 5: Priority Queue
   Purpose: Battery level ranking
   ================================================== */
void batteryRanking() {
    priority_queue<int> pq;
    int n, battery;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter battery level: ";
        cin >> battery;
        pq.push(battery);
    }

    cout << "Battery Ranking (High to Low):\n";
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}

/* ==================================================
   OPTION 6: Dynamic Programming
   Purpose: Minimum Fare Calculation
   ================================================== */
void minimumFare() {
    int distance;
    cout << "Enter travel distance (km): ";
    cin >> distance;

    vector<int> dp(distance + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= distance; i++) {
        dp[i] = dp[i - 1] + 2;     // cost per km
        if (i >= 5)
            dp[i] = min(dp[i], dp[i - 5] + 8);  // discount block
    }

    cout << "Minimum fare: " << dp[distance] << endl;
}

/* ==================================================
   MAIN FUNCTION
   ================================================== */
int main() {
    int choice;

    do {
        cout << "\n--- Energy-Optimized Mobility Classification System ---\n";
        cout << "1. Add Transport\n";
        cout << "2. Display Transport Classification\n";
        cout << "3. Greedy Vehicle Selection\n";
        cout << "4. Schedule Transport (Queue)\n";
        cout << "5. Show Transport Schedule\n";
        cout << "6. Battery Ranking (Priority Queue)\n";
        cout << "7. Minimum Fare Calculation (DP)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTransport(); break;
            case 2: displayTransport(); break;
            case 3: greedySelection(); break;
            case 4: enqueueTransport(); break;
            case 5: showQueue(); break;
            case 6: batteryRanking(); break;
            case 7: minimumFare(); break;
            case 0: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
