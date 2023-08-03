#include<bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> adj[1001];
bool visited[1001];

void input() {
    for (int i = 0; i < m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void lt() {
    vector<int> klt;
    memset(visited, false, sizeof(visited));
    bfs(l);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
           klt.push_back(i);
        }
    }
    if (klt.size() != 0) {
        for (int ver : klt) {
            cout << ver << endl;
        }
    } else {
        cout << "0"<< endl;
    }
}

int main() {
    cin >> n >> m >> l;
    input();
    lt();
    return 0;
}
