#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> C;
vector<vector<int>> dp;

int TSP(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return C[pos][0];
    }
    if (dp[mask][pos] != -1) 
        return dp[mask][pos];
    int minCost = INF;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            int newMask = mask | (1 << i);
            int newCost = C[pos][i] + TSP(newMask, i);
            minCost = min(minCost, newCost);
        }
    }
    return dp[mask][pos] = minCost;
}

int main() {
    cin >> n;
    C.resize(n, vector<int>(n));
    dp.resize(1 << n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> C[i][j];
        }
    }
    int minCost = TSP(1, 0);
    cout << minCost << endl;
    return 0;
}