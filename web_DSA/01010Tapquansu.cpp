#include <bits/stdc++.h>
using namespace std;
int arr[100], ans[100];
bool found;
void sinh(int n, int k) {
	int j = 0;
	for(int i = k; i >= 1; i--) {
		if(arr[i] != n - k + i) {
			j = i;
			break;
		}
	}
	if(j == 0) found = false;
	else {
		for(int i = 1; i < j; i++) {
			ans[i] = arr[i];
		}
		ans[j] = arr[j] + 1;
		for(int i = j + 1; i <= k; i++) {
			ans[i] = ans[i - 1] + 1;
		}
	}
}
int check(int n, int k) {
	set<int> st;
	for(int i = 1; i <= k; i++) {
		st.insert(arr[i]);
		st.insert(ans[i]);
	}
	int res = st.size() - k;
	return res;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		memset(arr, 0, sizeof arr);
		memset(ans, 0, sizeof ans);
		found = true;
		for(int i = 1; i <= k; i++) {
			cin >> arr[i];
		}
		sinh(n, k);
		if(!found) cout << k << endl;
		else {
			cout << check(n, k) << endl;
		}
	}
}
