#include <bits/stdc++.h>
using namespace std;

int main(){
        int n, m, s = 0, k;
        cin >> n >> m;
        int check[n + 1] = {};
        vector<vector<int>> a(n + 1);
        for (int i = 1; i <= n; i++){
            if (!check[i]) {
                s++;
                check[i] = 1;
                stack<int> st;
                st.push(i);
                while (st.size()){
                    k = st.top();
                    st.pop();
                    for (auto j : a[k]){
                        if (!check[j]){
                            check[j] = 1;
                            st.push(j);
                        }
                    }
                }
            }
        cout << s << endl;
    }
}