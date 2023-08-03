#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outtput.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map <int,int>mp; // truy van
    set<int> se; //cac ptu khac nhau 
    int n;cin >> n; 
    int a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for(int i =  n-1; i>= 0; i--){
        se.insert(a[i]);
        mp[i]= se.size();
    }
    int q; cin >> q;
    while (q--) {
        int l;  cin >> l;
        cout << mp[l] << endl;
    }
    return 0;
}
