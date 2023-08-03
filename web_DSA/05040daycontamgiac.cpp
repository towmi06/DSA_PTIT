#include<bits/stdc++.h>
using namespace std;

int a[maxn], dem[maxn];
int qhd(int a[], int n){
	int tang[n], giam[n], i, ans;
	tang[0]= 1; giam[n-1]=1;
	for(i = 1; i< n; i++){
		if(a[i]> a[i-1]) tang[i]= tang[i-1]+1;
		else tang[i]=1;
	}
	for(i = n-2; i >= 0;i--){
		if(a[i]> a[i+1]) giam[i]= giam[i+1]+1;
		else giam[i]=1;
	}
	ans = tang[0]+giam[0]-1;
	for(i =1; i<n; i++)
		ans = max(ans,tang[i]+ giam [i])-1;
	return ans;
}
main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << qhd(n);
	}
}