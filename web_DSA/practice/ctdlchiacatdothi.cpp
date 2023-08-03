#include <bits/stdc++.h>
using namespace std;
#define vc vector <int>
#define vp vector <vc>

vp M; int n, e;
vc m;

void DFS(int x) {
    m[x] = 0;
    for (auto i : M[x]) {
        if (m[i]) {
            DFS(i);
        }
    }
}

int tplt(int del) {
    int ans = 0;
    m = vc(n + 1, 1);
    m[del] = 0;
    for (int i = 1; i <= n; i++) {
        if (m[i]) {
            DFS(i);
            ans++;
        }
    }
    return ans;
}

void sol() {
    int x = 1, node = 0;
    cin >> n >> e;
    M = vp(n + 1);
    m = vc(n + 1, 1);
    for (int i = 0, u, v; i < e; i++) {
        cin >> u >> v;
        M[u].push_back(v);
        M[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        int tmp = tplt(i);
        if (tmp > x) {
            node = i;
            x = tmp;
        }
    }
    cout << node;
}

int main() {
    int t;    cin >> t;
    while (t--) {
        sol();
        cout << endl;
    }
}
