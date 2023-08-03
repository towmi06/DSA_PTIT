#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        stack<long long> st;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                if (s == "+") st.push(b + a);
                else if (s == "-") st.push(b - a);
                else if (s == "*") st.push(b * a);
                else st.push(b / a);
            } else {
                long long ans = strtoll(s.c_str(), NULL, 10);
                st.push(ans);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
