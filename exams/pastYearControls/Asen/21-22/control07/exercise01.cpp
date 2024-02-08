#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> all(N);
    unordered_map<int, int> ctr;
    unordered_set<int> uniques;

    for (int i = 0; i < N; ++i) {
        cin >> all[i];
        ctr[all[i]]++;
    }

    vector<int> noDubs;
    queue<int> dubs;

    for (auto e : all) {
        if (uniques.find(e) == uniques.end()) {
            if (ctr[e] > 1) {
                dubs.push(e);
            } else {
                noDubs.push_back(e);
            }
        }

        uniques.insert(e);
    }

    for (auto e : noDubs) {
        cout << e << " ";
    }

    while (!dubs.empty()) {
        cout << dubs.front() << " ";
        dubs.pop();
    }

    return 0;
}
