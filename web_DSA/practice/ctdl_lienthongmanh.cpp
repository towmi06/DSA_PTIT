#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
vector<int> adj[maxn];
int cnt = 1, res = 0;
int dis[maxn] = {}, low[maxn] = {};
stack<int> st;

void DFS(int u) {
    dis[u] = low[u] = cnt++;
    st.push(u);
    for (int v : adj[u]) {
        if (dis[v]) {
            low[u] = min(low[u], dis[v]);
        } else {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (dis[u] == low[u]) {
        ++res;
        int v = st.top();
        st.pop();
        dis[v] = low[v] = 1e9;
        while (v != u) {
            v = st.top();
            st.pop();
            dis[v] = low[v] = 1e9;
        }
    }
}

int main() {
    int t = 1, n, m, x, y;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            dis[i] = low[i] = 0;
        }
        while (m--) {
            cin >> x >> y;
            adj[x].push_back(y);
        }
        res = 0;
        for (int i = 1; i <= n; ++i) {
            if (!dis[i])   DFS(i);
        }
        cout << res;
    }
    return 0;
}
