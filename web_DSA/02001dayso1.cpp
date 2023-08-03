#include <bits/stdc++.h>
using namespace std;

int a[1001];

void Dq(int a[], int n){
	if(n>=1){
		cout << "[";
		for(int i = 0; i < n-1; i++){
			cout << a[i] << ' ';
		}
		cout << a[n-1] << "]\n";
		for(int i = 0; i < n-1; i++){
			a[i] = a[i] + a[i+1];
		}
		Dq(a, n-1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		Dq(a, n);
	}
	return 0;
}



