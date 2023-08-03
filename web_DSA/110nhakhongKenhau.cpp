#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outtput.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    ll dp[1000005];
    while(t--) {
        cin >> n;
        int a[n];
        for(int &i : a) cin >> i;
        if(n == 1) cout << a[0] << endl;
        else if(n == 2) cout << max(a[0], a[1]) << endl;
        else {
            dp[0] = a[0];
            dp[1] = max(a[0], a[1]);
            for(int i = 2; i < n; ++i) dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
            cout << dp[n - 1] << endl;
        }
    }
    return 0;
}