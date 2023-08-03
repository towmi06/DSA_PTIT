#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
int x[1005];
int a[1005];

void init() {
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 7;
}

map<int, int>mp;
void Br(int i) {
	for (int j = 1; j <= 4; j++) {
		x[i] = a[j];
		mp[x[i]] ++;
		if (i == m) {
			if (mp[2] > 0 && mp[3] > 0 && mp[5] > 0 && mp[7] > 0 && x[m] != 2) {
				for (int k = 1; k <= m; k++) {
					cout << x[k];
				}
				cout << endl;
			}
		} else Br(i + 1);
		mp[x[i]] --;
	}
}
int main(){
	init();
	cin >> n;
	for (int i = 4; i <= n; i++) {
		m = i;
		Br(1);
	}
	return 0;
}