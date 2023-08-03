#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void dik(vector<vector<pair<int, int>>>& graph, int src, vector<ll>& dist) {
    int n = graph.size();
    dist.assign(n, INF);
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (d > dist[u]) 
            continue;
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int T;cin >> T;
    while (T--) {
        int N, M;cin >> N >> M;

        int H1, S1, H2, S2;
        cin >> H1 >> S1 >> H2 >> S2;
        vector<vector<pair<int, int>>> graph(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }

        vector<ll> dist1, dist2;
        dik(graph, H1, dist1);
        dik(graph, H2, dist2);
        ll minDist1 = dist1[S1];
        ll minDist2 = dist2[S2];
        int num = 0;

        for (int i = 1; i <= N; i++) {
            if ((dist1[i] + minDist2 == minDist1 || dist2[i] + minDist1 == minDist2) &&
                (dist1[i] != INF && dist2[i] != INF)) {
                num++;
            }
        }

        if (num == 0) cout << "infinity\n";
        else  cout << num << endl;
    }
    return 0;
}
