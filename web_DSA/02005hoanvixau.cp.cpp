#include <bits/stdc++.h>
using namespace std;

void hv(string& S, int start, vector<string>& per) {
    if (start == S.length()) {
        per.push_back(S);
        return;
    }

    for (int i = start; i < S.length(); i++) {
        swap(S[start], S[i]);
        hv(S, start + 1, per);
        swap(S[start], S[i]);
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string S;
        cin >> S;

        vector<string> per;
        hv(S, 0, per);

        sort(per.begin(), per.end());

        for (const string& perm : per) 
            cout << perm << " ";
        cout << endl;
    }
    return 0;
}