#include<bits/stdc++.h>
using namespace std;

int tinh(string s){
    int n = s.length(), kq = 0;
    stack<int> st;
    st.push(-1);
    for(int i =0; i< n; i++){
        if(s[i] == '(') st.push(i);
        else {
            st.pop();
            if(!st.empty()){
                int j = st.top();
                kq = max(kq, i - j);
            } else st.push(i);
        }
    }
    return kq;
}
int main(){
    string s; cin >> s;
    cout << tinh << endl;
}