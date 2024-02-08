#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll value;
        cin >> value;
        if (value != -1) {
            pq.push(value);
        }
        else if (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    return 0;
}