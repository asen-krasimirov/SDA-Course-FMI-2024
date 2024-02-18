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

/* work in progress */

int N, id, t, Q;
unordered_map<int, vector<int>> um;

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> id >> t;
        um[id].push_back(t);
    }

    cin >> Q;

    while (Q--) {
        cin >> t;

        int elem = -1;
        int best = -1;
        int latestTime = -1;

        for (auto e : um) {
            auto lower_b = lower_bound(e.second.begin(), e.second.end(), t);

            // cout << e.first << " : " << lower_b - e.second.begin() << " ";
            int res = lower_b - e.second.begin();

            if (res > best) {
                best = res;
                elem = e.first;
                latestTime = *lower_b;
            }

            else if (res == best && latestTime > *lower_b) {
                best = res;
                elem = e.first;
                latestTime = *lower_b;
            }
        }

        if (best == -1) {
            cout << -1 << endl;
        } else {
            cout << elem << endl;
        }
    }

    return 0;
}
