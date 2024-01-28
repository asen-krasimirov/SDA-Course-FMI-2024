#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll N, K;
vector<ll> times;
ll maxTime = 1e14;

bool willDoInTime(ll time) {
    ll total = 0;

    for (auto t : times) {
        total += time / t;
    }

    return total >= N;
}

ll findMinTime() {
    ll l = 0, r = maxTime, ans = 0;

    ll bestAns = maxTime;

    while (l <= r) {
        ans = (l + r) / 2;
        // ans = l + (r - l) / 2;

        if (willDoInTime(ans)) {
            r = ans - 1;
            bestAns = min(bestAns, ans);
        } else {
            l = ans + 1;
        }
    }

    return bestAns;
}

int main() {
    cin >> N >> K;

    times = vector<ll>(K);

    for (int i = 0; i < K; ++i) {
        cin >> times[i];
    }

    cout << findMinTime();

    return 0;
}
