#include <bits/stdc++.h>
using namespace std;

string binary(int n){
    string s = "";
    queue<int> q;
    while (n > 0){
        q.push(n % 2);
        n /= 2;
    }
    while (!q.empty()) {
        if (q.front() == 0) {
            s = '0' + s;
        } else  {
            s = '1' + s;
            n--;
        }
        q.pop();
    }    return s;
}
int main(){
    int t;  cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << binary(i) << " ";
        }
        cout << endl;
    }
}