#include<bits/stdc++.h>
using namespace std;
using ll = long long;
queue<pair<ll,int>>q;
vector<ll>v;
void sinh68(){
	q.push({6,1});
	q.push({8,1});
	while(q.size()){
		pair<ll,int> t = q.front(); // lon hon kieu du lieu minh truyen vao ban dau 
		q.pop(); // day cap 6,1 ra
		v.push_back(t.first);// chua nhung so mk co
		if(t.second == 18) return ;
		q.push({t.first * 10+6, t.second + 1});
		q.push({t.first * 10+8, t.second +1});
		
	}
}
void xuli(){
	ll a, b;
	cin >> a >> b;
	// dau tien >= a;
	int pos1 = lower_bound(v.begin(), v.end(),a) - v.begin();
	// dau tien > b -> so lien trc upper_bound la so max <= b; 
	int pos2 = upper_bound(v.begin(), v.end(), b) - v.begin();
	cout << pos2 - pos1 << endl;
}
int main(){
	sinh68();
	sort(v.begin(), v.end());
	int t; cin >> t;
	while(t--){
		xuli();
	}
}