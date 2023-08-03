#include <bits/stdc++.h>
using namespace std;
int ok;
void khoitao(long long int s[], int n) {
	for(int i = 0; i < n; i++) {
		s[i] = i + 1;
	}
}
void sinh(long long int s[], int n, int k) {
	int i = k - 1;
	while(i >= 0 && s[i] == n - k + i + 1) {
		i--;
	}
	if(i == -1) {
		ok = 0;
	}
	else {
		s[i]++;
		for(int j = i + 1; j < k; j++) {
			s[j] = s[j - 1] + 1;
		}
	}
	
}
void hienthi(long long int arr[], int k) {
	for(int i = 0; i < k; i++) {
		char tmp = 'A' + arr[i] - 1;
		cout << tmp;
	}
	cout << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		long long int s[n + 2];
		khoitao(s, k);
		ok = 1;
		while(ok) {
			hienthi(s, k);
			sinh(s, n, k);
		}
	}
}

