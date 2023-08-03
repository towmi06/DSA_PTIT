#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

int n, m, cnt, cau, comp[MAXN], low[MAXN], num[MAXN];
bool is_cut[MAXN];
vector<int> adj[MAXN];

void DFS(int u, int p) {
    comp[u] = cnt;
    low[u] = num[u] = ++num[0];
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!num[v]) {
            children++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) cau++;
            if (p && low[v] >= num[u]) is_cut[u] = true;
        } else {
            low[u] = min(low[u], num[v]);
        }
    }

    if (!p && children > 1) is_cut[u] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
        if (!num[u]) {
            cnt++;
            DFS(u, 0);
        }
    }

    int cutver= 0;
    for (int i = 1; i <= n; i++) {
        cutver += is_cut[i];
    }

    cout << cutver << " " << cau << "\n";
    return 0;
}
