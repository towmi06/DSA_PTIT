#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
bool visited[MAX_N];
int parent[MAX_N];
vector<int> adj[MAX_N];

void BFS(int s){
    memset(visited, false, sizeof(visited));
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())  {
        int u = q.front();
        q.pop();
        for (int v : adj[u])  {
            if (!visited[v])      {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
} 

void findPath(int s, int t){
    if (!visited[t]) {
        cout << "No path";
    } else{
        vector<int> path;
        while (t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        for (int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    int test;
    cin >> test;
    while (test--) {
        int v, e, s;
        cin >> v >> e >> s;
        for (int i = 1; i <= v; i++) {
            adj[i].clear();
        }
        for (int i = 1; i <= e; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= v; i++)
        {
            if (s != i)
            {
                BFS(s);
                findPath(s, i);
            }
            memset(visited, false, sizeof(visited));
        }
    }
    return 0;
}
