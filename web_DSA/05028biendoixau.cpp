#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while (t--){
		int F[102][102], i, j, t,n, m;
		string s1, s2;
		cin >> s1 >> s2;
		n = s1.size(); m = s2.size();
		for(i = 1; i<= n; i++)	F[i][0]=i;
		for(i = 1; i <= m; i++)	F[0][i]=i;
		for(i= 1; i<= n; i++){
			for(j = 1; j<= m; j++){
				if(s1[i-1] == s2[j-1]) t = 0;
				else t=1;
				F[i][j]= min(F[i-1][j-1]+t, min(F[i-1][j], F[i][j-1])+1);
			}
		}
		cout<<F[n][m]<<endl;
	}
}