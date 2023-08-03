#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
bitset<1005> bs;
bool check;
int trace[1005];
int en;

void DFS(int u, int par){
    if(check)
        return;
    bs[u] = 1;
    for(int &i : a[u]){
        if(!bs[i]){
            trace[i] = u;
            DFS(i, u);
        }
        else {
            if(i != trace[u] and i == 1){
                check = 1;
                en = u;
                return;
            }
        }
    }
}

int main(){
    int t, v, e, x, y;
    cin >> t;
    while(t--) {
        memset(trace, 0, sizeof(trace));
        cin >> v >> e;
        a.resize(v + 5);
        while(e--){
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(int i = 1; i <= v; ++i)
            sort((a[i]).begin(), (a[i]).end());
        check = 0;
        DFS(1, 0);
        if(check){
            stack<int> st;
            cout << 1 << ' ';
            while(trace[en]){
                st.push(en);
                en = trace[en];
            }
            while(st.size()){
                cout << st.top() << ' ';
                st.pop();
            }cout << 1;
        } else cout << "NO";
        bs.reset();
        a.clear();
        cout << endl;
    }
    return 0;
}