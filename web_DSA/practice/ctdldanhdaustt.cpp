#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int t;   cin >> t;
    cin.ignore();
    while (t--) {
        string s; getline(cin, s);
        stack<int> st;
        int idx = 0;
        for (char c : s) {
            if (c == '(') {
                st.push(++idx);
                cout << idx << " ";
            }
            else if (c == ')') {
                cout << st.top() << " ";
                st.pop();
            }
        }
        cout << endl;
    }
    return 0;
}