#include <bits/stdc++.h>
using namespace std;
void Try(int n, int s, int m) {
	if(6 * n < 7 * m) {
		cout<< -1;
		return;
	}	
	bool ok = true;
	int res = 1;
	for(int i = 1; i <= s; i++) {
		if(n * i - s * m >= 0) {
			cout << i;
			return;
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n, s, m; cin >> n >> s >> m;
		Try(n, s, m);
		cout << endl;
	}
}
