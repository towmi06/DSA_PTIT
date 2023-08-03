#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

bool check(int u) {
    visited[u] = 1;
    for (int v : graph[u]) {
        if (visited[v] == 0) {
            if (check(v)) 
                return true;
        } else if (visited[v] == 1) 
            return true;
    }
    visited[u] = 2;
    return false;
}

void chutrinh() {
    int V, E, u, v;
    cin >> V >> E;
    graph.assign(V + 1, {});
    visited.assign(V + 1, 0);
    while (E--) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    bool c = false;
    for (int i = 1; i <= V; ++i) {
        if (!visited[i] && !c){ 
            c = check(i);
        }
    }
    cout << (c ? "YES" : "NO") << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        chutrinh();
    }
    return 0;
}
