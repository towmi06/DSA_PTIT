#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int v, e, s, t;
vector<bool> visited;
vector<int> parent;
vector<vector<int>> adj;

void BFS(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int k = q.front();
        q.pop();
        for (auto x : adj[k]) {
            if (!visited[x]) {
                visited[x] = true;
                parent[x] = k;
                q.push(x);
            }
        }
    }
}

void path(int s, int t){
    if (!visited[t])
        cout << "No path";
    else{
        vector<int> res;
        while (t != s){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << " ";
    }
    cout << endl;
}

int main(){
    int T; cin >> T;
    while (T--){
        cin >> v >> e >> s;
        adj.assign(v+1, vector<int>());
        visited.assign(v+1, false);
        parent.assign(v+1, 0);
        for (int i = 1; i <= e; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        BFS(s);
        for (int i = 1; i <= v; i++){
            if (i != s)
                path(s, i);
        }
    }
    return 0;
}
