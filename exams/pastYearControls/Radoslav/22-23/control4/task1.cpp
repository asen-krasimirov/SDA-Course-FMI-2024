#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
    int start, end;
    bool operator>(const Person& other)const {
        return end == other.end ? start > other.start : end > other.end;
    }
    bool operator<(const Person& other)const {
        return start == other.start ? end < other.end : start < other.start;
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<size_t, vector<size_t>, greater<size_t>> pq;
    vector<Person> arr;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        arr.push_back({ start,end });
    }
    size_t ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        pq.push(arr[i].end);
        while (!pq.empty() && arr[i].start >= pq.top()) {
            pq.pop();
        }
        if (ans < pq.size()) {
            ans = pq.size();
        }
    }
    cout << ans;
    return 0;
}