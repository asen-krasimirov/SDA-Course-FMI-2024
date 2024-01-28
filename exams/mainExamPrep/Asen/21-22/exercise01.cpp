#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <set>

using namespace std;

int N, M, ctr;
set<vector<int>> s;
set<vector<int>> uniques;
vector<vector<int>> nuCtr;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        vector<int> row(M);

        for (int j = 0; j < M; ++j) {
            cin >> row[j];
        }

        if (s.find(row) == s.end()) {
            s.insert(row);
            uniques.insert(row);
        } else {
            uniques.erase(row);
        }
    }

    cout << uniques.size();

    return 0;
}
