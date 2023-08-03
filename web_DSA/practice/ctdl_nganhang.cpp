#include<bits/stdc++.h>
using namespace std;

int n, q, s, a[9001], b[9001];
vector<vector<int> > v;
int res = 0, min_cost = 1e9;

int dem1() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(b[i] == 1) cnt++;
	}
	return cnt;
}
void process() {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += a[i] * b[i];
	} 
	vector<int> x;
	if(ans == s) {
		res = max(res, dem1());
		for(int i = 1; i <= n; i++) {
			if(b[i] == 1) {
				x.push_back(a[i]);
			}
		}
	}
	for(int it : x) min_cost = min(min_cost, it);
}
void Try(int i) {
	for(int j = 0; j <= 1; j++) {
		b[i] = j;
		if(i == n) {
			process();
		}else Try(i + 1);
	}
}
int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	while(q--) {
		cin >> s;
		Try(1);
		cout << res << " " << min_cost << endl;
	}
}