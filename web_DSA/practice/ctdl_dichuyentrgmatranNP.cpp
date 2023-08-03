#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1005;

int dp[MAX_N][MAX_N];
int A[MAX_N][MAX_N];

void tinh(int n, int m) {
    dp[1][1] = A[1][1];
    for (int i = 2; i <= m; i++) 
        dp[1][i] = dp[1][i - 1] + A[1][i];
    for (int i = 2; i <= n; i++) 
        dp[i][1] = dp[i - 1][1] + A[i][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) 
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + A[i][j];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> A[i][j]; 
    }
    tinh(n, m);
    cout << dp[n][m] << endl;

    return 0;
}
