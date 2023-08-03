#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tao() {
    queue<ll> q;
    vector<ll> v;
    q.push(4);
    q.push(7);
    v.push_back(4);
    v.push_back(7);
    while(q.front() < 1e9) {
        ll top = q.front();
        q.pop();
        ll x = top * 10 + 4;
        ll y = top * 10 + 7;
        q.push(x);
        q.push(y);
        v.push_back(x);
        v.push_back(y);
    }
    return v;
}

ll cal(ll a, ll b) {
    vector<ll> v = tao();
    ll res = 0, cnt = 0;
    int index = lower_bound(v.begin(), v.end(), a) - v.begin();
    while(a <= b) {
        cnt = min(v[index], b) - a + 1;
        res += cnt * v[index];
        a = v[index] + 1;
        index++;
    }
    return res;
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        ll a, b;  cin >> a >> b;
        ll res = cal(a, b);
        cout << res;
    }
    return 0;
}
