#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for(int nxt : graph[node])
        if(!visited[nxt])
            dfs(nxt);
}

int main() {
    graph = {{1,2},{2},{3},{}};
    visited.assign(4, false);

    dfs(0);
}
