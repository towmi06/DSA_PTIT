#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll tinh(ll n, const vector<ll>& a, const vector<ll>& b) {
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][1] = b[0];
    dp[0][0] = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
            dp[i][0] = dp[i - 1][1];
        } else {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outtput.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while (t--) {
        ll n;   cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i];

        ll minValue = tinh(n, a, b);
        cout << minValue << endl;
    }

    return 0;
}
