#include <bits/stdc++.h>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    vector<char> schedule(n, '-');
    vector<bool> slot(n, false);

    for(int i = 0; i < n; i++) {
        for(int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if(!slot[j]) {
                slot[j] = true;
                schedule[j] = jobs[i].id;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for(char c : schedule) {
        if(c != '-') cout << c << " ";
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    jobScheduling(jobs);
    return 0;
}
