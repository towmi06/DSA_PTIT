#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1001];

vector<int> v;

void Dq(int i, int pos, int cnt){
	if(cnt==k){
		for(int j = 0; j < k; j++){
			cout << a[j] << ' ';
		}
		cout << endl;
		return;
	}
	else{
		for(int j = pos; j < v.size(); j++){
			if(cnt <= k){
				a[i] = v[j];
				cnt++;
				Dq(i+1,j+1,cnt);
				cnt--;
			}
		}
	}
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	set<int> se;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(se.insert(x).second){
			v.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	Dq(0,0,0);
	return 0;
}


