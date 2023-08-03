#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        stack<int> st;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }
            res[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
