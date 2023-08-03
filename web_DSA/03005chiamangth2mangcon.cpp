#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		int arr[n+1];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}		
		sort(arr, arr+n);
		int sum1 = 0, sum2 = 0;
		for(int i = 0; i < min(k, n - k); i++) {
			sum1 += arr[i];
		}		
		for(int i = min(k, (n - k)); i < n; i++) {
			sum2 += arr[i];
		}		
		cout << sum2 - sum1 << endl;
	}
}
