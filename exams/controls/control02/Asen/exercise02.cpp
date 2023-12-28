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

long long bs(vector<pair<size_t, size_t>> &boxes, size_t val, size_t excludedIdx) {
    long long l = 0, r = boxes.size(), m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (boxes[m].first == val && m != excludedIdx) return m;

        if (boxes[m].first > val) r = m - 1;
        else l = m + 1;
    }

    return -1;
}

int main() {
    size_t T, N, X;
    cin >> T;

    for (size_t i = 0; i < T; ++i) {
        vector<pair<size_t, size_t>> boxes;

        cin >> X >> N;

        for (size_t j = 0; j < N; ++j) {
            size_t val;
            cin >> val;
            boxes.push_back(pair<size_t, size_t>(val, j));
        }

        sort(boxes.begin(), boxes.end());

        for (size_t j = 0; j < N; ++j) {
            long long neededIdx = bs(boxes, X - boxes[j].first, j);

            if (neededIdx != -1) {

                if (boxes[j].second < boxes[neededIdx].second)
                    cout << boxes[j].second + 1 << " " << boxes[neededIdx].second + 1 << endl;
                else
                    cout << boxes[neededIdx].second + 1 << " " << boxes[j].second + 1 << endl;

                break;
            }
        }
    }

    return 0;
}