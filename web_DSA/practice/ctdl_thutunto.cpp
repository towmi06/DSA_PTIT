#include<bits/stdc++.h>
using namespace std;
int n, a[10000], k, ok;
int cnt=1;

bool check(){
    if(cnt<2)return false;
    for(int i=2;i<=sqrt(cnt);i++)
        if(cnt%i==0)return false;
    return true;
}

void print(){
    cout<<cnt<<": ";
    for(int i=1;i<=k;i++)cout<<a[i]<<" ";
    cout<<endl;
}

void ktao(){
    for(int i=1;i<=k;i++)a[i]=i;
}

void sinh(){
    cnt++;
    int i=k;
    while(i>=1&&a[i]==n-k+i){
        i--;
    }
    if(i==0)ok=0;
    else {
        a[i]++;
        for(int j=i+1;j<=k;j++){
            a[j]=a[j-1]+1;
        }
    }
}

int main(){
    // int t; cin>>t;
    // while(t--){
        #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        cin>>n>>k;
        ok=1;
        ktao();
        while(ok){
            if(check())print();
            sinh();
        }
        cout<<endl; 
    // }
    return 0;
}