#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 1;
    string s, tmp;
    cin >> t;
    while(t--) {
        cin >> s;
        stack<string> st;
        for(int i = s.size() - 1; i >= 0; --i) {
            tmp = "";
            if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
                tmp += st.top();
                st.pop();
                tmp += st.top() + s[i];
                st.pop();
                st.push(tmp);
            }
            else st.push(tmp + s[i]);
        }
        while(st.size())  {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}