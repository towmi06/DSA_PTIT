#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y, s;
};

int main() {
    int t;   cin >> t;
    while (t--) {
        int n, m, ans = 1e9;     cin >> n >> m;
        vector<vector<bool>> check(n + 1, vector<bool>(m + 1, 1));
        vector<vector<int>> a(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        queue<point> q;
        q.push({1, 1, 0});

        while (!q.empty()) {
            point st = q.front();
            q.pop();

            if (st.x == n && st.y == m) {
                ans = min(ans, st.s);
            }
            int dx[] = {a[st.x][st.y], 0};
            int dy[] = {0, a[st.x][st.y]};
            for (int i = 0; i < 2; i++) {
                int x = st.x + dx[i];
                int y = st.y + dy[i];
                if (x <= n && y <= m && check[x][y]) {
                    check[x][y] = 0;
                    q.push({x, y, st.s + 1});
                }
            }
        }

        if (ans == 1e9)   cout << -1 << endl;
        else  cout << ans << endl;
   }
    return 0;
}
