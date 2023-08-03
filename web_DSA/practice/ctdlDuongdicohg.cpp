#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

vector<int> adj[MAXN]; 
bool visited[MAXN]; 
int trace[MAXN];
void TimDuongDi(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < adj[v].size(); i++) {
            int x = adj[v][i];
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
                trace[x] = v;
            }
        }
    }
}
void InDuongDi(int st, int en) {
    if (!visited[en]) {
        cout << "-1\n"; 
        return;
    }
    stack<int> path;
    path.push(en);
    while (trace[en]) {
        en = trace[en];
        path.push(en);
    }
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, u, v;
        cin >> n >> m >> u >> v;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
            trace[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        TimDuongDi(u);
        InDuongDi(u, v);
    }
    return 0;
}
