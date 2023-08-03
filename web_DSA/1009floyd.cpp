#include<bits/stdc++.h>
using namespace std;

int D[105][105];
main(){
    int t, n, m, u, v, w, i , j , k;
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++) D[i][j] = 1e9;
        D[i][i]= 0;
    }
    while(m--){
        cin >> u >> v >> w;
        D[u][v] = D[v][u]= w;
    }
    for(k = 1; k <= n; k++){
        for(int i = 1; i<= n ; i++){
            for(int j = 1; j<= n; j++)
            if(D[i][j] > D[i][k] + D[k][j])
                D[i][j] = D[i][k] + D[k][j];
        }
    }
    cin >> t;
    while(t--){
        cin >> u >> v;
        cout << D[u][v] << endl;
    }
}
