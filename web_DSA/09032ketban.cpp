#include<bits/stdc++.h>
using namespace std;

int n, m, ans, parent[100001], num[100001];
void init (){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        num[i]= 1;
    }
}
int find(int u){
    if(u != parent[u])  parent[u] = find(parent[u]);
    return parent[u];
}
void Union(int u, int v){
    int a = find(u), b = find(v);
    if(a == b) return;
    if(num[a] < num[b])swap (a, b);
    parent[b] = a;
    num[a] += num[b];
    ans = max(ans, num[a]);
}
main(){
    int t, u, v,parent[100001], num[100001]; cin >> t;
    while(t--){
        ans = 0; cin >> n >> m;
        init();
        while(m--){
            cin >> u >> v;
            Union(u, v);
        }
        cout << ans << endl;
    }
}