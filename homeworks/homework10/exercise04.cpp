#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

int T, N, M, K, L;
vector<bool> visited;
vector<vector<int>> adj;

int dfs(int v) {
    visited[v] = true;
    int ans = 1;

    for (auto el: adj[v]) {
        if (!visited[el]) {
            ans += dfs(el);
        }
    }

    return ans;
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M >> K >> L;
        adj = vector<vector<int>>(N + 1);

        for (int j = 0; j < M; j++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> components;
        visited = vector<bool>(N + 1);

        for (int j = 1; j <= N; j++) {
            if (!visited[j]) {
                components.push_back(dfs(j));
            }
        }

        long long ans = 0;
        for (int component: components) {
            ans += min((component - 1) * L + K, component * K);
        }

        cout << ans << endl;
    }

    return 0;
}
