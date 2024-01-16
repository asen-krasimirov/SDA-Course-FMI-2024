#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>

using namespace std;

unordered_map<string, vector<pair<string, bool>>> from;
vector<string> path;

long long N, M;
string start, cur, to;

bool isTherePath(string);

bool wrapIsTherePath(pair<string, bool> &str) {
    str.second = true;
    return isTherePath(str.first);
}

bool isTherePath(string s) {
    for (auto &str : from[s]) {
        if (str.first == start) {
            path.push_back(s);
            return true;
        }

        if (!str.second && wrapIsTherePath(str)) {
            path.push_back(s);
            return true;
        }
    }

    return false;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> cur >> to;

        if (from.find(cur) == from.end()) {
            from[cur] = vector<pair<string, bool>>();
        }

        from[cur].push_back({ to, false });
    }

    cin >> start;

    path.push_back(start);

    bool result = isTherePath(start);

    if (result) {
        reverse(path.begin(), path.end());
        for (auto &city : path) {
            cout << city << " ";
        }
    } else {
        cout << -1;
    }

    return 0;
}
