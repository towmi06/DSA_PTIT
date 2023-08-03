#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
vector<int> r_adj[100001];
bool visited[100001];
stack<int> st;
void inp() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}
void dfs1(int u) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			dfs1(v);
		}
	}
	st.push(u);
}
void dfs2(int u) {
	visited[u] = true;
	cout << u << " ";
	for(int v : r_adj[u]) {
		if(!visited[v]) {
			dfs2(v);
		}
	}
}
void SCC() {
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			dfs1(i);
		}
	}
	memset(visited, false, sizeof(visited));
	vector<int> a;
	int cnt = 0;
	while(!st.empty()) {
		int u = st.top(); st.pop();
		if(!visited[u]) {
			//a.push_back(u);
			//cnt++;
			dfs2(u);
			cout << endl;
		}
	}
//	if(cnt == 1) cout << "YES\n";
//	else {
//		cout << "NO\n";
//		cout << a[1] << " " << a[0];
//	}
}
int main() {
	inp();
	SCC();
}