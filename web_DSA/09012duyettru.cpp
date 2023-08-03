#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;

vector<int> adj[MAXN];
int low[MAXN], num[MAXN], parent[MAXN];
bool arti[MAXN];
int n, m, counter, root, rootC;

void DFS(int u) {
    low[u] = num[u] = ++counter;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(num[v] == 0) {
            parent[v] = u;
            if(u == root) rootC++;
            DFS(v);
            if(low[v] >= num[u]) arti[u] = true;
            low[u] = min(low[u], low[v]);
        } else if(v != parent[u]) {
            low[u] = min(low[u], num[v]);
        }
    }
}

void check() {
    counter = 0;
    memset(num, 0, sizeof(num));
    memset(arti, false, sizeof(arti));
    for(int i = 1; i <= n; i++) {
        if(num[i] == 0) {
            root = i;
            rootC= 0;
            DFS(i);
            arti[root] = (rootC > 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        check();
        for(int i = 1; i <= n; i++) {
            if(arti[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

}
