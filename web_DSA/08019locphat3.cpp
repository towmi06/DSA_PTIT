#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;  cin >> t;
    while (t--){
        int n;  cin >> n;
        queue<string> dq;
        stack<string> ans;
        dq.push("6");
        dq.push("8");
        while (dq.size()) {
            string k = dq.front();
            ans.push(k);
            dq.pop();
            if (k.size() != n) {
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        cout << ans.size() << endl;
        while (ans.size()){
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
}