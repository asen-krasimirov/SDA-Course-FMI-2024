#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    set<vector<int>> set;
    for (int i = 0; i < n; i++) {
        vector<int> v(m);
        for (int j = 0; j < m; j++) {
            cin >> v[j];
        }
        if (set.find(v) != set.end()) {
            set.erase(v);
        }
        else {
            set.insert(v);
        }
    }
    cout << set.size();
    return 0;
}