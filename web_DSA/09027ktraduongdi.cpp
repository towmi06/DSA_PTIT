#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

bool chuaxet[N];
vector<int> List[N];

void DFS(int u) {
    chuaxet[u] = false;
    for (int v : List[u]) {
        if (chuaxet[v]) {
            DFS(v);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            List[i].clear();
            chuaxet[i] = true;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            List[u].push_back(v);
            List[v].push_back(u);
        }
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            memset(chuaxet, true, sizeof(chuaxet));
            DFS(u);
            if (chuaxet[v]) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    return 0;
}
