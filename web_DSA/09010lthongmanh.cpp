/*#include<bits/stdc++.h>
using namespace std;
bool visited[1005];
vector<int> adj[1005];

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])      DFS(v);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        DFS(1);
        bool lthongmanh = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                lthongmanh = false;
                break;
            }
        }
        if (lthongmanh) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}*/
// yes no va in ra sotplthong 
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz size()
#define vi vector<int>

const int MAXN = 10005;

int n, m, cnt, res;
int dis[MAXN], low[MAXN];
bool visited[MAXN];
vi a[MAXN], b[MAXN];
stack<int> st;

void dfs(vi c[], int u) {
    visited[u] = 1;
    for (int i : c[u])
        if (!visited[i])
            dfs(c, i);
}

void dfs2(int u) {
    dis[u] = low[u] = cnt++;
    st.push(u);
    for (int i : a[u]) {
        if (dis[i])
            low[u] = min(low[u], dis[i]);
        else {
            dfs2(i);
            low[u] = min(low[u], low[i]);
        }
    }
    if (dis[u] == low[u]) {
        ++res;
        int top = st.top();
        st.pop();
        dis[top] = low[top] = 1e9;
        while (top != u) {
            top = st.top();
            st.pop();
            dis[top] = low[top] = 1e9;
        }
    }
}

bool check() {
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            a[x].pb(y);
            b[y].pb(x);
        }
        dfs(a, 1);
        if (check()) {
            memset(visited, 0, sizeof visited);
            dfs(b, 1);
            if (check()) {
                cout << "YES\n";
                continue;
            }
        }
        cnt = res = 0;
        memset(dis, 0, sizeof dis);
        memset(low, 0, sizeof low);
        for (int i = 1; i <= n; ++i)
            if (!dis[i])
                dfs2(i);
        cout << "NO " << res << '\n';
        for (int i = 1; i <= n; ++i) {
            a[i].clear();
            b[i].clear();
        }
        while (!st.empty())
            st.pop();
    }
    return 0;
}
