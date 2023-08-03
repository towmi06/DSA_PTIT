#include<bits/stdc++.h>
using namespace std;
int main(){
    int t = 1;
    cin >> t;
    string s;
    int cnt;
    while(t--){
        cin >> cnt;
        cout << cnt << ' ';
        cin >> s;
        int i, j;
        i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) --i;
        if(i < 0){
            cout << "BIGGEST" << endl;
            continue;
        }
        j = s.size() - 1;
        while(s[i] >= s[j]) j--;
        swap(s[i], s[j]);
        sort(s.begin() + i + 1, s.end());
        cout << s << endl;
    }
    return 0;
}