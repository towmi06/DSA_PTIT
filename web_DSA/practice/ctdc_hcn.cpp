#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll hcn(int a[], int n){
	int l[n], r[n];
	stack<int> st;
	for (int i = 0; i < n; i++){
		while (!st.empty() && a[st.top()] >= a[i]) {
			st.pop() ;
		}
		if (st.empty()) l[i] = 0;
		else l[i] = st.top() + 1;
		st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--){
    	while (!st.empty() && a[st.top()] >= a[i]){
    		st.pop();
		}
		if (st.empty()) r[i] = n - 1;
		else r[i] = st.top() - 1;
		st.push(i);
	}
    ll res = 0;
    for(int i = 0; i < n; i++){
    	res = max(res, (ll)a[i] * (r[i] - l[i] + 1));
	}
	return res;
}

void check(){
	int m, n;
	cin >> m >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = m - a[i];
	}
	cout << max(hcn(a, n), hcn(b, n));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t = 1; 
	while (t--){
		check();
		cout << endl;
	}
	return 0;
}

