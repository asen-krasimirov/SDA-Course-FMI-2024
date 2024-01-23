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

ll T, X, N;
const ll INF = 1e10;

ll bs(ll toFind, vector<pair<ll, ll>> &boxes, ll exclude) {
    ll l = 0, r = boxes.size(), m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (boxes[m].first == toFind && boxes[m].second != exclude) {
            return boxes[m].second;
        }

        if (boxes[m].first > toFind) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return -1;
}

int main() {
    cin >> T;

    while (T--) {
        cin >> X >> N;

        vector<pair<ll, ll>> boxes;

        for (ll i = 0; i < N; ++i) {
            int x;
            cin >> x;
            boxes.push_back({ x, i});
        }

        sort(boxes.begin(), boxes.end());

        for (auto b : boxes) {
            ll toFind = X - b.first;
            ll res = bs(toFind, boxes, b.second);

            if (res != -1) {
                cout << min(res, b.second) + 1 << " " << max(res, b.second) + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
