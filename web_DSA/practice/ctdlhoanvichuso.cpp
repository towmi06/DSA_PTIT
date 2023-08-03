#include <bits/stdc++.h>
using namespace std;

bool ck(string s) {
    bool ktra = true;
    for(int i = 0; i < s.size(); i++) 
        if(s[i] == s[i+1]) 
            ktra = false;
    return ktra;
}

int main() {
    int t;   cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        if(ck(s) && s.size() >= 1 && s.size() <= 9) {
            sort(s.begin(), s.end());
            do {
                if(s[0] != '0')cout << s << endl;
                else {
                	for(int i = 1; i < s.size(); i++) 
                        cout << s[i];
					cout << endl;
				}
            } while (next_permutation(s.begin(), s.end()));
        }
    }
    return 0;
}