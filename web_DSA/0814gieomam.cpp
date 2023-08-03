#include<bits/stdc++.h>
using namespace std;

int a[505][505];
int n, m;
inline int BFS(){
    int f[505][505] = {}, cnt1 = 0;
    queue<pair<int, int>> q;
    pair<int, int> p;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cnt1 += a[i][j] == 1;
            if(a[i][j] == 2){
                q.push({i, j});
                f[i][j] = 1;
            }
        }
    }
    if(!cnt1) return 0;
    while(q.size())
    {
        p = q.front();
        q.pop();
        if(p.first - 1 >= 1 and a[p.first - 1][p.second] == 1)
        {
            a[p.first - 1][p.second] = 2;
            --cnt1;
            if(!cnt1) return f[p.first][p.second];
            f[p.first - 1][p.second] = f[p.first][p.second] + 1;
            q.push({p.first - 1, p.second});
        }
        if(p.first  + 1 <= n and a[p.first + 1][p.second] == 1)
        {
            a[p.first  + 1][p.second] = 2;
            --cnt1;
            if(!cnt1) return f[p.first ][p.second];
            f[p.first  + 1][p.second] = f[p.first ][p.second] + 1;
            q.push({p.first  + 1, p.second});
        }
        if(p.second - 1 >= 1 and a[p.first ][p.second - 1] == 1)
        {
            a[p.first ][p.second - 1] = 2;
            --cnt1;
            if(!cnt1) return f[p.first ][p.second];
            f[p.first ][p.second - 1] = f[p.first ][p.second] + 1;
            q.push({p.first , p.second - 1});
        }
        if(p.second + 1 <= m and a[p.first ][p.second + 1] == 1)
        {
            a[p.first ][p.second + 1] = 2;
            --cnt1;
            if(!cnt1) return f[p.first ][p.second];
            f[p.first ][p.second + 1] = f[p.first ][p.second] + 1;
            q.push({p.first , p.second + 1});
        }
    }
    return -1;
}
int main(){
    int t = 1;   cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];
        cout << BFS() << endl;
    }
    return 0;
}