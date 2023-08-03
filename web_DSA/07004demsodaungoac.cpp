#include<bits/stdc++.h>
using namespace std;

int count(string s) {
    int n = s.length();
    stack<char> st;
    if (n % 2 != 0) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push('(');
        } else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(')');
            }
        }
    }
    int op = 0,cl= 0;
    while (!st.empty()) {
        if (st.top() == '(') 
            op++;
        else if (st.top() == ')') {
            cl++;
        }
        st.pop();
    }
    int minRev = (op + 1) / 2 + (cl + 1) / 2;
    return minRev;
}

int main() {
    int t; cin >> t;
    cin.ignore();
    while (t--) {
        string s; getline(cin, s);
        int result = count(s);
        cout << result << endl;
    }
    return 0;
}
