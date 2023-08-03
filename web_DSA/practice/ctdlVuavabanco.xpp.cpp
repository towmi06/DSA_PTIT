#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

using ll = long long;

int n, Xma, Yma, Xvua, Yvua;
int ce = INT_MAX;

int vuaX[8] = {1, -1, 0, 0, 1, -1, 1, -1},
    vuaY[8] = {1, 1, 1, -1, -1, -1, 0, 0};

int maX[8] = {-1, -2, -2, -1, 1, 2, 2, 1},
    maY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int d1[1005][1005], d2[1005][1005],
    f1[1005][1005], f2[1005][1005];

char c[1005][1005];

void king(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    f1[i][j] = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int a = x.first,
            b = x.second;
        for (int k = 0; k < 8; k++) {
            int i1 = a + vuaX[k];
            int j1 = b + vuaY[k];
            if (i1 < 1 || i1 > n || j1 < 1 || j1 > n || f1[i1][j1])
                continue;
            d1[i1][j1] = d1[a][b] + 1;
            q.push({i1, j1});
            f1[i1][j1] = 1;
        }
    }
    return;
}

void knight(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    f2[i][j] = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int a = x.first,
            b = x.second;
        for (int k = 0; k < 8; k++) {
            int i2 = a + maX[k];
            int j2 = b + maY[k];
            if (i2 < 1 || i2 > n || j2 < 1 || j2 > n || f2[i2][j2])
                continue;
            d2[i2][j2] = d2[a][b] + 1;
            q.push({i2, j2});
            f2[i2][j2] = 1;
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] == '#') {
                f1[i][j] = f2[i][j] = 1;
            } else if (c[i][j] == 'M') {
                Xma = i;
                Yma = j;
            } else if (c[i][j] == 'T') {
                Xvua = i;
                Yvua = j;
            }
        }
    }
    king(Xvua, Yvua);
    knight(Xma, Yma);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d1[i][j] == d2[i][j] && d1[i][j] != 0) {
                ce = min(ce, d1[i][j]);
            }
        }
    }
    cout << ce << endl;
    return 0;
}
