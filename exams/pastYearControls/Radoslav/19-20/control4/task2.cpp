#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
    int time, value;
    bool operator<(const Interval& other) const {
        return this->time < other.time || (this->time == other.time && this->value > other.value);
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> map;
    multiset<Interval> ms;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        ms.insert({ start,1 });
        ms.insert({ end,-1 });
    }
    queue<int> q;
    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        ms.insert({ query,0 });
        q.push(query);
    }
    int counter = 0;
    for (auto& interval : ms) {
        counter += interval.value;
        if (interval.value == 0) {
            map[interval.time] = counter;
        }
    }

    while (!q.empty()) {
        cout << map[q.front()] << " ";
        q.pop();
    }

    return 0;
}
