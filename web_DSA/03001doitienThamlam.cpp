#include <bits/stdc++.h>
using namespace std;

int main (){
	int a[]= {1,2,5,10,20,50,100,200,500,1000};
	int t,n, kq, i; cin >> t;
	while(t--){
		cin >>n;  kq = 0;
		for (i = 9; i>= 0; i--){
			kq += n/a[i];
			n %= a[i];
		}
		cout << kq << endl;
	}	
	return 0;
}