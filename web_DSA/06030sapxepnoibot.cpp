#include<bits/stdc++.h>
using namespace std;
int main(){
    int t = 1, n;cin >> t;
    while(t--){
        cin >> n;
        int a[n], m = n - 1;
        for(int &i : a) cin >> i;
        vector<vector<int>> ans;
        for(int i = 0; i < m; ++i){
            bool notSwap = 1;
            for(int j = 0; j < m - i; ++j)
                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                    notSwap = 0;
                }
            if(notSwap) break;
            vector<int> v(n);
            for(int i = 0; i < n; ++i) v[i] = a[i];
            ans.push_back(v);
        }
        for(int i = ans.size(); i; --i) {
            cout << "Buoc " << i << ": " << ' ';
            for(int j : ans[i - 1]) cout << j << ' ';
            cout << endl;
        }
    }
    return 0;
}