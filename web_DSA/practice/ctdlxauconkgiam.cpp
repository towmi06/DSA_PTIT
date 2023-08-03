#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int dp[n];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    int ans = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (s[j] <= s[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
