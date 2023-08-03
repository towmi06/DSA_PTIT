#include<bits/stdc++.h>
using namespace std;
int parent[100005], num[100005];
void makeset(){
	for(int i=1;i<=100000;i++){
	  	parent[i] = i; num[i] = 1;
	}
}
int find(int u){
	if(u == parent[u]) return u;
	return find(parent[u]);
}
void Union(int u,int v){
 	u = find(u); v = find(v);
 	if(u == v) return;
 	if(num[u] < num[v]) swap(u,v);
 	parent[v] = u;
 	num[u] += num[v];
}
main(){
	int t,x,y,z; cin >> t;
	makeset();
	while(t--){
		cin >> x >> y >> z;
		if(z == 1) Union(x,y);
		else cout << (find(x) == find(y)) << endl;
	}
}
