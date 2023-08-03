#include<bits/stdc++.h>
using namespace std;
int n, m, daxet[10], a[10], stt = 0;
void in(){
    stt++;
    if(stt % m == 0){
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    } 
}
void quaylui(int i){
    for(int j = 1; j <= n; j++){
        if(!daxet[j]){ 
            a[i] = j; daxet[j] = 1;
            if (i == n) in();
            else quaylui(i + 1);
            daxet[j] = 0;
        }
    }
}
main(){
    cin >> n >> m;
    quaylui(1);
}
