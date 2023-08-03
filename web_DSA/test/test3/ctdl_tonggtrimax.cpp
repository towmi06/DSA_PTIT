#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; cin >> n >> t;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> c[i];
    vector<int> dp(t + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = t; j >= a[i]; j--) 
            dp[j] = max(dp[j], dp[j - a[i]] + c[i]);
    }
    
    int max_value = dp[t];
    cout << max_value << endl;
    
}