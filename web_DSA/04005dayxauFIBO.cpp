#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f[93];

void fb(){
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i <= 92; i++){
		f[i] = f[i-1]+f[i-2];
	}
}

char Find(ll n, ll k){
	if(n==1){
		return 'A';
	}
	else if(n==2){
		return 'B';
	}
	if(k <= f[n-2]){
		return Find(n-2, k);
	}
	else{
	    return 	Find(n-1, k-f[n-2]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fb();
	int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		cout << Find(n, k) << endl;
	}
	return 0;
}
