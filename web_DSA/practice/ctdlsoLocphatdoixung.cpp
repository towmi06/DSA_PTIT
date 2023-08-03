#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    string t(s.rbegin(), s.rend());
    return s + t;
}

void testCase() {
    int n;
    cin >> n;
    queue<string> q;
    q.push("");
    vector<string> res, ves;
    while (!q.empty()) {
        string t = q.front();
        q.pop();
        if (t.length() * 2 > n) break; // sửa lỗi: kiểm tra độ dài chuỗi t đã nhân đôi hay chưa
        if (t != "") {
            res.push_back(solve(t));
        }
        if (t.length() * 2 < n) { // sửa lỗi: kiểm tra độ dài chuỗi t đã nhân đôi hay chưa
            q.push(t + '6');
            q.push(t + '8');
        }
    }
    sort(res.begin(), res.end()); // sắp xếp các chuỗi tăng dần
    for (string s : res) {
        ves.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        cout << ves[i] << " ";
    }
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}
