#include<bits/stdc++.h>
using namespace std;

inline void DFS(int x, vector<vector<int>> &a, bitset<1005> &bs, vector<pair<int, int>> &vp)
{
    bs[x] = 1;
    for(int &i : a[x]) {
        if(!bs[i]){
            vp.push_back({x, i});
            DFS(i, a, bs, vp);
        }
    }
}

int main(){
    int t = 1, e, v, u, x, y;
    cin >> t;
    while(t--){
        cin >> v >> e >> u;
        vector<vector<int>> a(v + 5);
        bitset<1005> bs;
        vector<pair<int, int>> res;
        while(e--)  {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        DFS(u, a, bs, res);
        if(res.size() == v - 1)
            for(pair<int, int> &i : res)
                cout << i.first << ' ' << i.second << endl;
        else cout << -1 << endl;
    }
    return 0;
}