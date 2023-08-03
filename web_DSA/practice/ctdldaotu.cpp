#include <iostream>
#include <stack>
#include <string>

using namespace std;
void rev(string& str){
    stack<char> word; 
    string result; 
    for (char c : str) {
        if (c == ' ') { 
            while (!word.empty()) { 
                result += word.top();
                word.pop();
            }
            result += ' '; 
        }
        else { 
            word.push(c);
        }
    }
    while (!word.empty()) {
        result += word.top();
        word.pop();
    }
    str = result; 
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(); 
    for (int t = 1; t <= T; t++) {
        string str;
        getline(cin, str);
        rev(str);
        cout << str << endl; 
    }
    return 0;
}
