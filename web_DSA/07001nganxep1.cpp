#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	stack<ll>st;
	string s;
	while (cin >> s) {
		if (s == "push") {
			ll n;cin >> n;
			cin.ignore();
			st.push(n);
		} else if (s == "pop") {
			st.pop();
		} else {
			vector<ll>v;
			if (st.empty()) 
				cout << "empty" << endl;
		    else {
				while (!st.empty()) {
					ll tmp = st.top();
					st.pop();
					v.push_back(tmp);
				}
				for (int i=v.size()-1;i>=0;i--) {
					cout << v[i] << " ";
					st.push(v[i]);
				}
				cout << endl;
			}
		}
	}
	return 0;
}