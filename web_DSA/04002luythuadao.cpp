#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

long long Pow(long long n, long long k){
	if(k==0){
		return 1;
	}
	long long tmp = Pow(n,k/2)%mod;
	if(k%2==1){
		return ((tmp*tmp)%mod*n%mod)%mod;
	}
	else{
		return (tmp*tmp)%mod;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		long long n = stoll(s);
		reverse(s.begin(), s.end());
		long long k = stoll(s);
		cout << Pow(n,k) << endl;
	}
	return 0;
}


