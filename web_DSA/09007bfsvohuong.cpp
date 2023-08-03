#include<bits/stdc++.h>
using namespace std;
const int MAX = 1005;

bool checkxet[MAX];
vector<int> List[MAX];
int truoc[MAX], n, m, s, t;

void BFS(int s){
    queue<int> Q;
    memset(checkxet, true, sizeof(checkxet));
    checkxet[s] = false;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i = 0; i < List[u].size(); i++){
            int v = List[u][i];
            if(checkxet[v]){
                checkxet[v] = false;
                Q.push(v);
                truoc[v] = u;
            }
        }
    }
}

void Path(int u){
    if(u == s) cout << s << " ";
    else if(truoc[u] == -1) cout << "-1";
    else{
        Path(truoc[u]);
        cout << u << " ";
    }
}

int main (){
    int t; cin >> t;
    while(t--){
        cin >> n >> m >> s >> t;
        memset(truoc, -1, sizeof(truoc));
        for(int i = 1; i <= n; i++) List[i].clear();
        for(int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            List[u].push_back(v);
            List[v].push_back(u);
        }
        BFS(s);
        Path(t);
        cout << endl;
    }
    return 0;
}
