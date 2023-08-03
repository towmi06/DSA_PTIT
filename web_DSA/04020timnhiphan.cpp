#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n,int x){
	int l = 0, r=n-1;
	while(l <= r){
		int m = (l+r)/2;
		if(a[m] == x){
			return m;
		}
		else if(a[m] > x){
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int res = binarySearch(a,n,k);
		if(res == -1){
			cout << "NO";
		}
		else{
			cout << res+1;
		}
		cout << endl;
	}
	return 0;
}
