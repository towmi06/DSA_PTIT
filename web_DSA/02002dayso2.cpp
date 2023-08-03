#include <bits/stdc++.h>
using namespace std;

int a[1001];
vector <string> v;

void Dq(int a[], int n){
	if(n>=1){
		string s= "[";
		
		for(int i = 0; i < n-1; i++){
			s = s + to_string(a[i]);
			s+= " ";
		}
		s = s + to_string(a[n - 1]) +"]";
		v.push_back(s);
		
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
		reverse(v.begin() , v.end());
		for(auto x: v){
			cout << x << " ";
		}
		cout << endl;
		v.clear();
	}
	return 0;
}



