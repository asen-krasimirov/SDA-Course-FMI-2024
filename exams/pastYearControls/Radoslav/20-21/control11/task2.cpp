#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
    int to, weight;
};

bool hasCycle(unordered_map<int, vector<Node>>& g, int current, vector<bool>& visited) {
    if (visited[current]) {
        return true;
    }

    visited[current] = true;

    for (auto& el : g[current]) {
        if (hasCycle(g, el.to, visited)) {
            return true;
        }
    }

    visited[current] = false;
    return false;

}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n, m;
        cin >> n >> m;
        unordered_map<int, vector<Node>> g;
        for (int j = 0; j < m; j++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            g[from].push_back({ to,weight });
        }
        vector<bool> visited(n, false);

        bool flag = false;

        for (int j = 0; j <= n; j++) {
            if (!visited[j]) {
                if (hasCycle(g, j, visited)) {
                    flag = true;
                    break;
                }
            }
        }

        cout << flag;

    }
    return 0;
}