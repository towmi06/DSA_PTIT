#include<bits/stdc++.h>
using namespace std;
bool  chuaxet[1005];
vector<int> List [1005];
int truoc[1005], n, m, s, t;

void DFS(int u){
    chuaxet[u]= false;
    for(int i = 0; i < List[u].size(); i++){
        int v = List[u][i];
        if(chuaxet[v]){
            truoc[v] = u; 
            DFS(v);
        }
    }
}

void printPath(int u){
    if(u == s){
        cout << u << " ";
        return;
    }
    printPath(truoc[u]);
    cout << u << " ";
}

int main (){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> s >> t;
        for(int i = 1; i <= n; i++){
            chuaxet[i] = true;
            List[i].clear();
            truoc[i] = -1;
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            List[u].push_back(v);
        }
        DFS(s);
        if(chuaxet[t]) cout << "-1\n";
        else printPath(t);
        cout << endl;
    }
    return 0;
}
