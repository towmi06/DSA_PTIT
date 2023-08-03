#include<bits/stdc++.h>
using namespace std;

bool chuaxet[1005];
vector<int> List[1005];
int truoc[1005], n, m, s, t;

void BFS(int s){
    queue<int> Q;
    Q.push(s);
    chuaxet[s] = false;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < List[u].size(); i++){
            int v = List[u][i];
            if(chuaxet[v]){
                chuaxet[v] = false;
                truoc[v] = u;
                Q.push(v);
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> s >> t;
        memset(chuaxet, true, sizeof(chuaxet));
        for(int i = 1; i <= n; i++) List[i].clear();
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            List[u].push_back(v);
        }
        BFS(s);
        if(!chuaxet[t]){
            stack<int> ans;
            ans.push(t);
            while(ans.top() != s){
                ans.push(truoc[ans.top()]);
            }
            while(!ans.empty()){
                cout << ans.top() << " ";
                ans.pop();
            }
            cout << endl;
        }
        else cout << "-1" << endl;
    }
    return 0;
}
