#include <iostream>
#include <vector>
using namespace std;

int main() {
    int teams = 5;
    vector<vector<int>> graph(teams);

    // Add edges (team battles)
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);

    cout << "Team 1 plays with: ";
    for(int opp : graph[0]) cout << opp << " ";
}
