#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> numb(int n) {
    vector<string> result;
    result.push_back("6");
    result.push_back("8");
    queue<string> q;
    q.push("6");
    q.push("8");
    
    while (result.size() < n) {
        string top = q.front();
        q.pop();
        string s1 = top + "6";
        string s2 = top + "8";
        
        q.push(s1);
        q.push(s2);
        reverse(s1.begin(), s1.end());
        result.push_back(top + "6" + s1);
        
        reverse(s2.begin(), s2.end());
        result.push_back(top + "8" + s2);
    }
    return result;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n;  cin >> n;
        vector<string> s= numb(n);
        for (const string& num : s)
            cout << num << ' ';        
        cout << endl;
    }
    return 0;
}
