#include <bits/stdc++.h>
using namespace std;

int main() {
    
    std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int off = n + 1;

    map<int, set<int>> g;
    for (int i = 0; i < m; i++) {
        int x, y, weight;
        cin >> x >> y >> weight;
        if (weight == 2) {
            int newNode = off++;
            g[x].insert(newNode);
            g[newNode].insert(x);
            g[y].insert(newNode);
            g[newNode].insert(y);
        }
        else {
            g[x].insert(y);
            g[y].insert(x);
        }
    }

    int start, end;
    cin >> start >> end;
    vector<bool> visited(1000000, false);
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({ start,0});

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (node == end) {
            cout << dist;
            break;
        }

        for (auto& el : g[node]) {
            if (!visited[el]) {
                visited[el] = true;
                q.push({ el,dist + 1 });
            }
        }
    }

    return 0;
}
