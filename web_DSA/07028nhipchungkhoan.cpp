#include <bits/stdc++.h>
using namespace std;

main(){
    int t, n, a[100005];
    stack<int> st;
    cin >> t;
    while (t--){
        cin >> n; st.push(0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            while(st.size()> 1 && a[st.top()] <= a[i]) st. pop();
            cout << i - st.top()<< " ";
            st.push(i);
        }
        while(st.size()) st.pop();
        cout << endl;
    }
}