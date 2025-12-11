#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<vector<pair<int,int>>> graph;

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d > dist[node]) continue;

        for(auto edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;

            if(dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    int n = 4;
    graph.assign(n, {});

    graph[0].push_back({1, 3});
    graph[1].push_back({2, 2});
    graph[2].push_back({3, 4});

    vector<int> result = dijkstra(0, n);

    for(int d : result) cout << d << " ";
}
