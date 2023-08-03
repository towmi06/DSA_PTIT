#include <bits/stdc++.h>
using namespace std;
int arr[100][100], n;
int pos[2][2] = {{1, 0}, {0, 1}};
int ans[100];
bool ok;
void hienthi(int n) {
	ok = true;
	for(int i = 1; i < n; i++) {
		if(ans[i] == 0) cout << "D";
		else if(ans[i] == 1) cout << "R";
	}
	cout << " ";
}
void Try(int i, int x, int y) {
	if(x == n - 1 && y == n - 1) {
		hienthi(i);
		return;
	}
	for(int j = 0; j <= 1; j++) {
		int x1 = x + pos[j][0];
		int y1 = y + pos[j][1];		
		if(arr[x1][y1] == 1 && x1 < n && y1 < n) {
			ans[i] = j;
			Try(i + 1, x1, y1);
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(ans, 0, sizeof(ans));
		ok = false;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		if(arr[0][0] == 0) {
			cout << -1;
		}
		else {
			Try(1, 0, 0);
			if(!ok) cout << -1;
		}
		cout << endl;
	}
}
