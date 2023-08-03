#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int n;  cin >> n;
        queue<string> q;
        q.push("6");
        q.push("8");
        int lott = pow(2, n + 1) - 2;
        cout << lott << endl;
        while (!q.empty()){
            string k = q.front();
            q.pop();
            cout << k << " ";
            if (k.size() != n){
                q.push(k + "6");
                q.push(k + "8");
            }
        }
        cout << endl;
    }
    return 0;
}
