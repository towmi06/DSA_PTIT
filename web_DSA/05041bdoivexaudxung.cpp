#include<bits/stdc++.h>
using namespace std;

int qhd(string s){
	int n = s.length();
	int F[n+1][n+1];
	memset(F, 0,sizeof(F));
	for(int i =n-2; i>= 0; i--){
		for(int j = i +1; j < n ; j ++){
			if(s[i]== s[j]) F[i][j] = F[i+1][j-1];
			else F[i][j]= min(F[i+1][j], F[i][j-1]) +1;
		}
	}
	return F[0][n - 1];
}
int main(){
	int t; cin >> t;
	while(t --){
		string s; cin >> s;
		cout << qhd(s) << endl;
	}
}