#include<bits/stdc++.h>
using namespace std;
int l1[] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int r1[] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l2[] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};

inline string Change(string &s, int a[])
{
    string res = "";
    for (int i = 0; i < 10; ++i)
        res += s[a[i]];
    return res;
}
int main(){
    int t = 1; cin >> t;
    while (t--)  {
        unordered_map<string, int> m;
        int ans = 1e9;
        string a, b = "1238004765";
        for (int i = 0; i < 10; ++i){
            int x; cin >> x;
            a += to_string(x);
        }
        queue<pair<string, int>> q1, q2;
        q1.push({a, 0});
        q2.push({b, 0});
        pair<string, int> top;
        while (q1.size()){
            top = q1.front();
            q1.pop();
            pair<string, int> tmp = {Change(top.first, l1), top.second + 1};
            if (!m[tmp.first]){
                m[tmp.first] = tmp.second;
                q1.push(tmp);
            }
            tmp.first = Change(top.first, r1);
            if (!m[tmp.first]){
                m[tmp.first] = tmp.second;
                q1.push(tmp);
            }
            if (tmp.second == 14)
                break;
        }
        while (q2.size()){
            top = q2.front();
            q2.pop();
            if (m[top.first])
                ans = min(ans, m[top.first] + top.second);
            pair<string, int> tmp = {Change(top.first, l2), top.second + 1};
            q2.push(tmp);
            tmp.first = Change(top.first, r2);
            q2.push(tmp);
            if (tmp.second == 14)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}