
#include <bits/stdc++.h>
using namespace std;

int t, n, m;
const int M = 1e9;
int A[1005][1005];
int d[1005][1005];

void BFS(int i, int j) {
    queue<pair<int, int>>q;
    q.push({i, j});
    d[i][j] = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int a = x.first, b = x.second;
        if (a == n && b == m) {
        break;
        }
        int a1, b1;
        if (a + 1 <= n) {
            a1 = a + abs(A[a][b] - A[a + 1][b]), b1 = b;
            if (d[a1][b1] == M && a1 <= n){
                d[a1][b1] = d[a][b] + 1;
                q.push({a1, b1});
            }
        }
        if (b + 1 <= m){
            a1 = a; b1 = b + abs(A[a][b] - A[a][b + 1]);
            if (d[a1][b1] == M && b1 <= m){
                d[a1][b1] = d[a][b] + 1;
                q.push({a1, b1});
            }
        }
        if (a + 1 <= n && b + 1 <= m){
            a1 = a + abs(A[a][b] - A[a + 1][b + 1]);
            b1 = b + abs(A[a][b] - A[a + 1][b + 1]);

            if (d[a1][b1] == 1e9 && (a1 <= n) && (b1 <= m)){
                d[a1][b1] = d[a][b] + 1;
                q.push({a1, b1});
            }
        }
    }
    return;
}

int main(){
    cin >> t;
    while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            d[i][j] = M;
        }
    }
    BFS(1, 1);
    if (d[n][m] == M) cout << -1;
    else cout << d[n][m];
    cout << endl;
    }
    return 0;
}