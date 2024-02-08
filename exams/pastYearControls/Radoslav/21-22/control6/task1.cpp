#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void dfs(vector<vector<int>>& g, int current, vector<bool>& visited, int component, vector<int>& components) {
    for (auto& el : g[current]) {
        if (!visited[el]) {
            visited[el] = true;
            components[el] = component;
            dfs(g, el, visited, component, components);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    int q;
    cin >> q;
    int component = 1;
    vector<int> components(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(g, i, visited, component, components);
            component++;
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << (components[x] == components[y]) << " ";
    }

    return 0;
}
