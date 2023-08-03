#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;  cin >> t;
    while (t--) {
        int n;  cin >> n;
        queue<string> dq;
        dq.push("6");
        dq.push("8");
        stack<string> s;
        while (!dq.empty()) {
            string k = dq.front();
            dq.pop();
            s.push(k);
            if (k.size() != n){
                dq.push(k + "6");
                dq.push(k + "8");
            }
        }
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        } cout << endl;
    }
    return 0;
}