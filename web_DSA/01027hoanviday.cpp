#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v(n);
vector<int> res(n);

void sinh(){
	sort(v.begin(), v.end());
	while(1){
		for(int i = 0; i < n; i++){
			cout << v[i] << ' ';
		}
		cout << endl;
		int i = n-2;
		while(i >= 0 && v[i] > v[i+1]){
			i--;
		}
		if(i < 0)
			break;
		else{
			int j = n- 1;
			while(v[i] > v[j]){
				j--;
			}
			swap(v[i], v[j]);
			int l = i+1, r = n- 1;
			while(l < r){
				swap(v[l], v[r]);
				l++;
				r--;
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sinh();
	return 0;
}

