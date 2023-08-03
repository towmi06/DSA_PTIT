#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int a[], int n) {
    int maxSum = a[0];  
    int currentSum = a[0]; 
    for (int i = 1; i < n; i++) {
        currentSum = max(a[i], currentSum + a[i]);
		maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int result = findMaxSum(a, n);
        cout << result << endl;
    }

    return 0;
}
