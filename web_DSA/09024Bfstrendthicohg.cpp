#include <bits/stdc++.h>
using namespace std;

bool chuaxet[1005];
vector<int> List[1005];

void BFS(int u) {
    queue<int> q;
    chuaxet[u] = false;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i = 0; i < List[v].size(); i++) {
            int x = List[v][i];
            if (chuaxet[x]) {
                chuaxet[x] = false;
                q.push(x);
            }
        }
    }
}

int main() {
    int T;cin >> T;
    while (T--) {
        int n, m, u; cin >> n >> m >> u;
        for (int i = 1; i <= n; i++) {
            chuaxet[i] = true;
            List[i].clear();
        }
        for (int i = 1; i <= m; i++){
            int a, b; cin >> a >> b;
            List[a].push_back(b);
        }
        BFS(u);
        cout << endl;
    }
    return 0;
}