#include<bits/stdc++.h>

using namespace std;

bool F[1005][1005]; int n;
int qhd(string s){
	int n = s.size(), ans = -1e9, i , j;
	memset(F, false, sizeof(F));
	for(i = n - 1; i>= 0; i --){
		for(j=i; j<= n-1; j++){
			if(i == j) F[i][j] = true;
			else if(s[i] == s[j]){
				if(j - i == 1) F[i][j] = true;
				else F[i][j] = F[i +1][j-1];
			}
			if(F[i][j]) ans = max(ans, j-i+1);
		}
	}
	return ans;
}

int main(){
	int t; cin >> t;
	while(t --){
		string s; cin >> s;
		cout << qhd(s) << endl;
	}
}