#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.deadline < b.deadline;
}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(jobs[i].profit);
        if (pq.size() > jobs[i].deadline) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        maxProfit += pq.top();
        pq.pop();
    }

    cout << maxProfit << endl;

    return 0;
}
