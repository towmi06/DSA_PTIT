#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
    int t = 1, n, k, mod = 1e9 + 7;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k > n)
            cout << 0 << endl;
        else if(!k)
            cout << 1 << endl;
        else {
            ll res = 1;
            for(int i = n - k + 1; i <= n; ++i)
                res = (res * i) % mod;
            cout << res << endl;
        }
    }
    return 0;
}