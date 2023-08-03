#include<bits/stdc++.h>
using namespace std;

const int MAX = 1005;

bool chuaxet[MAX];
vector<int> List[MAX];

void DFS(int u){
    chuaxet[u] = false;
    for(int v : List[u]){
        if(chuaxet[v])  DFS(v);
    }
}

int main(){
    int t, x, y, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) {
            chuaxet[i] = true;
            List[i].clear();
        }
        for(int i = 1; i < n; i++){
            cin >> x >> y;
            List[x].push_back(y);
            List[y].push_back(x);
        }
        DFS(1);
        bool check = true;
        for(int i = 1; i <= n; i++){
            if(chuaxet[i]){
                check = false;
                break;
            }
        }
        if(check)  cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
