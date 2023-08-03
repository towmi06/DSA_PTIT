#include <bits/stdc++.h>
using namespace std;
vector<int> tree[1005];

void BFS(int u, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<pair<int, int>> spTree;

    visited[u] = true;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < tree[v].size(); i++) {
            int neighbor = tree[v][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                spTree.push_back(make_pair(v, neighbor));
            }
        }
    }
    if (spTree.size() != n - 1) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < spTree.size(); i++) {
        cout << spTree[i].first << " " << spTree[i].second << endl;
    }
}

int main() {
    int t;cin >>t;
    while (t--) {
        int n,m, u;
        cin >> n >> m >> u;
        for (int i = 1; i <= n; i++) {
            tree[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        BFS(u, n);
    }

    return 0;
}
