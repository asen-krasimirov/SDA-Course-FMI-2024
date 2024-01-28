#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int k, t, b;
    cin >> k >> t >> b;
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = k * b;
    vector<int> result;
    cin >> n;
    int groups = 0;
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        if (i % t == 0 && !pq.empty()) {
            groups++;
            for (int j = 0; j < k; j++) {
                int value = pq.top();
                result.push_back(value);
                pq.pop();
            }
        }
        pq.push(q[i]);
    }
    cout << "--------------------\n";

    if (groups < b) {
        for (int j = 0; j < k; j++) {
            int value = pq.top();
            result.push_back(value);
            pq.pop();
        }
    }
    for (auto& el : result) {
        cout << el << " ";
    }

    return 0;
}
