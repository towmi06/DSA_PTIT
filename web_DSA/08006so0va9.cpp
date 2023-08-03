 #include<bits/stdc++.h>
 using namespace std;

 void xuli(int n){
    queue<int > Q;
    Q.push(9);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        if(x%n == 0){
            cout << x << endl;
            break;
        }
        Q.push(x*10);
        Q.push(x*10+9);
    }
 }
 int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        xuli(n);
    }
 }