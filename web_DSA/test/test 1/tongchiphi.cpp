#include <bits/stdc++.h>
using namespace std;
main(){
	int n, k, x, i;
	cin >> n >> k;
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	for (i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}
	long long ans = 0;
	while (pq.size() > 1) {
		long long sum = 0, max = 0, min = 0;
		if (pq.size() >= k) {
			min = pq.top();
			int t = k;
			while(t--) {
				if (t == 0) max = pq.top();
				sum += pq.top();
				pq.pop();
			}
		} else {
			min = pq.top();
			while (!pq.empty()) {
				if (pq.size() == 1) max = pq.top();
				sum += pq.top();
				pq.pop();
			}
		}
		ans += max - min;
		pq.push(sum);
	}
	cout << pq.top() << endl << ans;
}
