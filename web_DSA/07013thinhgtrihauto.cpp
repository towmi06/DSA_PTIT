#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int x = s[i] - '0';
                st.push(x);
            } else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int x;
                if (s[i] == '+') {
                    x = a + b;
                } else if (s[i] == '-') {
                    x = b - a;
                } else if (s[i] == '*') {
                    x = a * b;
                } else {
                    x = b / a;
                }
                st.push(x);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
