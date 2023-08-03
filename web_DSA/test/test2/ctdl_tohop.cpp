#include <bits/stdc++.h>
using namespace std;
int k; string s;int x[1005];
set<string>p;
void sl(int i) {
	for (int j = x[i - 1] + 1; j <= s.size()- 1-k + i; j++) {
		x[i] = j;
		if (i == k) { 
			string tmp = "";
			for (int h = 1; h <= k; h++) {
				tmp += s[x[h]];
			}
			p.insert(tmp);
		} else sl(i + 1);
	}
}
int main(){
	int t; cin >> t;
	while (t--) {
		cin >> s >> k;
		s = "@" + s;
		sl(1);
		for (auto &x : p) 
			cout << x << endl;
		p.clear();
	}
	return 0;
}