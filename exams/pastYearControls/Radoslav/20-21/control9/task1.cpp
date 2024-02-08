#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int m;
    cin >> m;
    vector<multiset<int>> graph(m);
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            graph[i].insert(x);
            graph[x].insert(i);
        }
    }
    vector<int> components;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        bool flag = true;
        int from, to;
        cin >> from;
        for (int j = 0; j < n - 1; j++) {
            cin >> to;
            if (graph[from].find(to) == graph[from].end()) {
                flag = false;
            }
            from = to;
        }
        cout << flag << " ";
    }
    return 0;
}