#include <bits/stdc++.h>
using namespace std;

#define MAXN 20

int n, MIN = INT_MAX;
int a[MAXN][MAXN];
bitset<MAXN> bs;
vector<int> res, v;

void timChuTrinhNhoNhat(int i, int sum = 0, int cnt = 1) {
    if (sum > MIN) return;
    if (cnt == n) {
        if (MIN > sum + a[i][1]) {
            MIN = sum + a[i][1];
            res = v;
        }
        return;
    }
    for (int j = 2; j <= n; ++j) {
        if (!bs[j]) {
            bs[j] = 1;
            v[cnt] = j;
            timChuTrinhNhoNhat(j, sum + a[i][j], cnt + 1);
            bs[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    res.resize(n + 1);
    v.resize(n + 1);
    res[n] = v[n] = 1;
    bs[1] = 1;
    timChuTrinhNhoNhat(1);

    cout << "(1,";
    for (int i = 1; i < n; ++i) {
        cout << res[i] << ",";
    }
    cout << res[n] << ")\n";
    cout << MIN;
    return 0;
}
