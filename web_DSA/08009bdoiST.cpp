#include <bits/stdc++.h>
using namespace std;

int bdoi(int s, int n){
    int a[20001] ={0}, i;
    queue<int> Q;
    Q.push(s);
    while(a[n]==0){
        int x = Q.front(); Q.pop();
        if(x-1 >0 && a[x-1]==0){
            a[x-1] = a[x]+1;
            Q.push(x-1);
        }
        if(x*2 < 20000 && a[x*2] == 0){
            a[x*2]= a[x]+1;
            Q.push(x*2);
        }
    }
    return a[n];
}
int main(){
    int t, s, n;  cin >> t;
    int cnt = 0;
    while (t--) {
        cin>> s >> n;
        cout <<bdoi(s,n) << endl;
    }
}