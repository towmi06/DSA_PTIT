#include<bits/stdc++.h>
using namespace std;

int n, m, u, v;
struct canh {
    int dau, cuoi, ts;
};
int cmp(canh a, canh b) {
    return a.ts < b.ts;
}
int parent[1005], num[1005];
void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        num[i] = 1;
    }
}
int find(int u) {
    if (u == parent[u]) return u;
    return find(parent[u]);
}
int Union(int u, int v) {
    int a = find(u), b = find(v);
    if (a == b) return 0;
    if (num[a] < num[b]) swap(a, b);
    parent[b] = a;
    num[a] += num[b];
    return 1;
}
int main() {
    int t, n, m, dau, cuoi, ts;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<canh> ds(m);
        for (int i = 0; i < m; i++) {
            cin >> dau >> cuoi >> ts;
            ds[i] = { dau, cuoi, ts };
        }
        sort(ds.begin(), ds.end(), cmp);
        init(n);
        int kq = 0;
        for (int i = 0; i < m; i++) {
            if (Union(ds[i].dau, ds[i].cuoi)) {
                kq += ds[i].ts;
            }
        }
        cout << kq << endl;
    }
}