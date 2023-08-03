#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, x;
    cin >> n;
    string s;
    deque<int> dq;
    map<string, function<void()>> commands = {
        {"PUSHFRONT", [&dq, &x](){cin >> x; dq.push_front(x);}},
        {"PRINTFRONT", [&dq](){if (!dq.empty()) cout << dq.front() << endl; else cout << "NONE" << endl;}},
        {"POPFRONT", [&dq](){if (!dq.empty()) dq.pop_front();}},
        {"PUSHBACK", [&dq, &x](){cin >> x; dq.push_back(x);}},
        {"PRINTBACK", [&dq](){if (!dq.empty()) cout << dq.back() << endl; else cout << "NONE" << endl;}},
        {"POPBACK", [&dq](){if (!dq.empty()) dq.pop_back();}}
    };

    while (n--)
    {
        cin >> s;

        commands[s]();
    }

    return 0;
}