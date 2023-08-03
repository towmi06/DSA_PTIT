#include <bits/stdc++.h>
using namespace std;
int arr[105];
bool visited[105];
int n, k;
int ans;
int a[105];
void kiemtra() {
	bool flag = true;
	for(int i = 1; i < k; i++) {
		if(arr[a[i]] >= arr[a[i + 1]]) {
			flag = false;
			break;
		}
	}
	if(flag) ans++;
}
void sinh(int i) {
	if(i > k) {
		kiemtra();
		return;
	}
	for(int j = a[i - 1] + 1; j <= n; j++) {
		a[i] = j;
		sinh(i + 1); 
	}
}
int main() {
	cin >> n >> k;
	ans = 0;
	memset(visited, false, sizeof visited);
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sinh(1);
	cout << ans << endl;
}
