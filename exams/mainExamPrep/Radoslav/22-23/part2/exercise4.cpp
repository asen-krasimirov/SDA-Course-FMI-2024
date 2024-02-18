#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int p;
    cin >> p;
    vector<int> path;
    unordered_set<int> forbidden;
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        path.push_back(x);
        forbidden.insert(x);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        forbidden.insert(x);
    }
    int res = 0;
    for (int i = 0; i < p-1; i++) {
        int from = path[i];
        int to = path[i + 1];
        queue<pair<int, int>> q;
        forbidden.erase(from);
        forbidden.erase(to);
        q.push({ from,0 });
        while (!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (node == to) {
                res += dist;
                break;
            }
            for (auto& b : graph[node]) {
                if (forbidden.find(b) == forbidden.end()) {
                    q.push({ b,dist + 1 });
                }
            }
        }
    }
    cout << res;
    return 0;
}
