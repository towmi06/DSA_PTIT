#include <bits/stdc++.h>
using namespace std;

int Find(long long n, long long k){
	if(k%2==1){
		return 1;
	}
	if(k == pow(2,n-1)){
		return n;
	}
	else if(k < pow(2,n-1)){
		return Find(n-1,k);
	}
	else{
		return Find(n-1,k-pow(2,n-1));
	}
}

int main(){
	
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		cout << Find(n,k) << endl;
	}
	return 0;
}


