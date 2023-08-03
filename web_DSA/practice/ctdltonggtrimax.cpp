#include <bits/stdc++.h>
using namespace std;

int n, M;
int w[5005], v[5005];
int dp[5005][5005];

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][M] << endl;
    return 0;
}
