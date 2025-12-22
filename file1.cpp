#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/* ================= HASH TABLE (MAP) ================= */
map<int, string> players;

/* ================= LINKED LIST ================= */
struct Match {
    string name;
    Match* next;
};

Match* head = NULL;

/* ================= GRAPH ================= */
vector<vector<pair<int,int> > > graph;

/* ================= FUNCTIONS ================= */

void addPlayer() {
    int id;
    string name;
    cout << "Enter Player ID: ";
    cin >> id;
    cout << "Enter Player Name: ";
    cin >> name;
    players[id] = name;
    cout << "Player added successfully.\n";
}

void searchPlayer() {
    int id;
    cout << "Enter Player ID to search: ";
    cin >> id;

    if (players.find(id) != players.end())
        cout << "Player Found: " << players[id] << endl;
    else
        cout << "Player Not Found.\n";
}

void addMatch() {
    string name;
    cout << "Enter Match Name: ";
    cin >> name;

    Match* newMatch = new Match;
    newMatch->name = name;
    newMatch->next = NULL;

    if (head == NULL)
        head = newMatch;
    else {
        Match* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newMatch;
    }
    cout << "Match added successfully.\n";
}

void showMatches() {
    Match* temp = head;
    cout << "Match Schedule:\n";
    while (temp != NULL) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "END\n";
}

void rankingSystem() {
    priority_queue<int> pq;
    int n, score;
    cout << "Enter number of players: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> score;
        pq.push(score);
    }

    cout << "Player Rankings:\n";
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}

void createGraph() {
    int V, E;
    cout << "Enter number of teams: ";
    cin >> V;
    cout << "Enter number of matches: ";
    cin >> E;

    graph.clear();
    graph.resize(V);

    cout << "Enter edges (team1 team2 weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
}

void dfsUtil(int node, vector<int>& visited) {
    visited[node] = 1;
    cout << node << " ";

    for (size_t i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i].first;
        if (!visited[nextNode])
            dfsUtil(nextNode, visited);
    }
}

void DFS() {
    if (graph.empty()) {
        cout << "Create graph first.\n";
        return;
    }
    vector<int> visited(graph.size(), 0);
    cout << "DFS Traversal: ";
    dfsUtil(0, visited);
    cout << endl;
}

void BFS() {
    if (graph.empty()) {
        cout << "Create graph first.\n";
        return;
    }

    vector<int> visited(graph.size(), 0);
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (size_t i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            if (!visited[nextNode]) {
                visited[nextNode] = 1;
                q.push(nextNode);
            }
        }
    }
    cout << endl;
}

void dijkstra() {
    if (graph.empty()) {
        cout << "Create graph first.\n";
        return;
    }

    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int> > pq;

    dist[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (size_t i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }

    cout << "Shortest Path from Team 0:\n";
    for (int i = 0; i < V; i++)
        cout << "Team " << i << " : " << dist[i] << endl;
}

void sortSearch() {
    int n;
    cout << "Enter number of scores: ";
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; i++)
        cin >> scores[i];

    sort(scores.begin(), scores.end());

    cout << "Sorted Leaderboard:\n";
    for (int i = n - 1; i >= 0; i--)
        cout << scores[i] << " ";

    int key;
    cout << "\nEnter score to search: ";
    cin >> key;

    if (binary_search(scores.begin(), scores.end(), key))
        cout << "Score Found\n";
    else
        cout << "Score Not Found\n";
}

/* ================= MAIN ================= */
int main() {
    int choice;

    do {
        cout << "\n--- Smart City Sports Management System ---\n";
        cout << "1. Add Player\n2. Search Player\n3. Add Match\n4. Show Matches\n";
        cout << "5. Player Ranking\n6. Create Graph\n7. DFS\n8. BFS\n";
        cout << "9. Dijkstra\n10. Sorting & Searching\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: addPlayer(); break;
            case 2: searchPlayer(); break;
            case 3: addMatch(); break;
            case 4: showMatches(); break;
            case 5: rankingSystem(); break;
            case 6: createGraph(); break;
            case 7: DFS(); break;
            case 8: BFS(); break;
            case 9: dijkstra(); break;
            case 10: sortSearch(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
