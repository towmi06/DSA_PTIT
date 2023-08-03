#include <bits/stdc++.h>
using namespace std;
int tinh(int n, int x, int y, int z){
	int F[105]= {0}, i;
	F[1]=x;
	for(i=2;i<=n; i++){
		if(i%2==0)
			F[i]= min (F[i-1] + x, F[i/2]+ z);
		else F[i]= min (F[i-1] + x, F[(i+1)/2]+ z-y);
	}
	return F[n];
}
int main ()