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
int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        for (int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int index;
        vector<int> distances(n + 1);
        for (int j = 0; j < n; j++) {
            distances[j] = INT_MAX;
        }
        cin >> index;
        queue<pair<int, int>> q;
        q.push({ index,0 });
        vector<bool> visited(n + 1, false);
        visited[index] = true;
        while (!q.empty()) {
            int curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            distances[curr] = dist;
            for (auto n : graph[curr]) {
                if (!visited[n]) {
                    visited[n] = true;
                    q.push({ n,dist + 6 });
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (index == j)
                continue;
            if (distances[j] != INT_MAX) {
                cout << distances[j] << " ";
            }
            else {
                cout << -1 << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}