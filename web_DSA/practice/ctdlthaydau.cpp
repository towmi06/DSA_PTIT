#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        stack<int> st;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
                cnt++;
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    int j = st.top(); st.pop();
                    s[j] = '0';
                    s[i] = '1';
                    cnt--;
                } else {
                    s[i] = '-';
                    s.insert(i + 1, "1");
                }
            }
        }
        while (cnt--) {
            int j = st.top(); st.pop();
            s[j] = '-';
            s.insert(j + 1, "1");
        }
        cout << s << endl;
    }
    return 0;
}
