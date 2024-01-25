#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>

using namespace std;

typedef long long ll;

unordered_map<ll, ll> um;

int main() {
    ll N, x;
    cin >> N;

    for (ll i = 0; i < N; ++i) {
        cin >> x;
        um[x]++;
    }

    int sum = 0;    // bug (wrong test case #4)

    for (auto e : um) {
        if (e.second % 2 == 1) {
            sum += e.first * e.second;
        }
    }

    cout << sum;

    return 0;
}
