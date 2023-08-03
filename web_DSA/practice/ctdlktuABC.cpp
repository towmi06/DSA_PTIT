#include <iostream>
#include <string>
using namespace std;

void generate_strings(string s, int a_count, int b_count, int c_count, int n) {
    if (s.length() == n) {
        if (a_count <= b_count && b_count <= c_count) {
            cout << s << endl;
        }
        return;
    }
    if (a_count < n-2) {
        generate_strings(s + 'A', a_count + 1, b_count, c_count, n);
    }
    if (b_count < n-1) {
        generate_strings(s + 'B', a_count, b_count + 1, c_count, n);
    }
    if (c_count < n) {
        generate_strings(s + 'C', a_count, b_count, c_count + 1, n);
    }
}


int main() {
    int n;
    cin >> n;
    generate_strings("", 0, 0, 0, n);
    return 0;
}
