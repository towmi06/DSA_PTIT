#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
void check(const string s){
    int n = s.size();
    dp.resize(n,vector<int>(n,0));
    for(int i = 0; i< n; i++){
        dp[i][i]= 1;
    }
    for(int len = 2; len <= n; len ++){
        for(int i =0; i<n-len+1; i++){
            int j = i+len-1;
            if(s[i] == s[j] && (len == 2 || dp[i+1][j-1]==1))
                dp[i][j]=1;
        }
    }
} 
bool dx(int l, int r){
    return dp[l][r]==1;
}

int main(){
    string s; cin >> s;
    check(s);
    int m; cin >> m;
    while(m--){
        int l,r; cin >> l >> r;
        if(dx(l-1,r-1)) cout << "YES" << endl;
        else cout << "NO"<<endl;
    }
}