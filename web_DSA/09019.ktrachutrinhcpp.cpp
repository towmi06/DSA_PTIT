#include<bits/stdc++.h>
using namespace std;

int n, m, u, v, parent[1001], num[1001];
void init(){
    for(int i =1 ; i <= n; i++){
        parent[i]= i;
        num[i]= 1;
    }
}
int find(int u){
    if( u!= parent[u])  parent[u] = find(parent[u]);
    return parent[u];
}
bool Union(int u, int v){
    int  a = find(u), b= find(v);
    if(a==b) return false; 
    if(num[a] < num[b]) swap(a, b);
    parent[b] = a;
    num[a] += num[b];
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        init();
        bool check = false;
        while (m--){
            cin >> u >> v;
            if(!Union(u,v)) check = true;
        }
        if(check) cout << "YES\n"; 
        else cout << "NO\n"; 
    }
    return 0;
}
