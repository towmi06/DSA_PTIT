#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll t, n;

int main(){
	cin >> t;
	while (t--) {
		cin >> n;
		queue<ll>q;
		q.push(1);
		while (1) {
			ll x = q.front();
			q.pop();
			if (x % n == 0) {
				cout << x << endl;
				break;
			}
			q.push(x * 10);
			q.push(x * 10 + 1ll * 1);
		}
	}
	return 0;
}