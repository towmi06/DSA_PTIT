#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main (){
    string s;  cin >> s;
    stack<pair<char, int>> st;
    int cnt = 0, ans = 0;
    for(int i = 0; i < s.size(); i++)    {
        if(!st.empty() && ((s[i] == ')' && st.top().first == '(') || (s[i] == ']' && st.top().first == '[')))
        {
            st.pop();
            if(!st.empty()) ans = max(ans, cnt - st.top().second);
            else ans = cnt;
        }else {
            if(s[i] == '[') cnt++;
            st.push({s[i], cnt});
        }
    }
    cout << ans;
    return 0;
}
