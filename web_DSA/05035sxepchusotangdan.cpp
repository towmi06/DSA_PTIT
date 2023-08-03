#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int counts(int N) {
    vector<vector<int>> DP(N + 1, vector<int>(10, 0));
    for (int j = 0; j <= 9; j++) {
        DP[1][j] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                DP[i][j] = (DP[i][j] + DP[i-1][k]) % MOD;
            }
        }
    }
    int result = 0;
    for (int j = 0; j <= 9; j++) {
        result = (result + DP[N][j]) % MOD;
    }
    
    return result;
}

int main() {
    int T;cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        int result = counts(N);
        cout << result << endl;
    }
    return 0;
}
