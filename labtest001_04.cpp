#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    vector<bool> slot(maxDeadline, false);
    vector<char> result(maxDeadline, '-');
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(jobs[i].deadline - 1, maxDeadline - 1); j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << totalProfit << endl;

    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != '-') {
            cout << result[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
