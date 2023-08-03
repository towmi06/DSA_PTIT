#include<bits/stdc++.h>
using namespace std;

bool check(string s) {
	stack<char> st;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') {
			st.push(s[i]);
		}else if(s[i] == ')' && st.top() == '(') {
			st.pop();
		}
	}
	return st.empty();
}
void solve(string s) {
	stack<char> st;
	int ans = 0;
	for(int i = 0; i < s.length(); i++) {
		int tmp;
		if(s[i] == '(') {
			st.push(s[i]);
			tmp = 0;
		}else if(s[i] == ')' && st.top() == '(') {
			st.pop();
			tmp += 1;
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
} 
int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outtput.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int k; cin >> k;
	cin.ignore();
		string s;
		getline(cin, s);
		if(check(s)) 
			solve(s);
}