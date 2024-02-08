#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    size_t to, weight;
};

bool hasCycle(vector<vector<Edge>>& graph, vector<bool>& visited, size_t current) {
    if (visited[current]) {
        return true; 
    }

    visited[current] = true;

    for (auto& node : graph[current]) {
        if (hasCycle(graph, visited, node.to)) {
            return true;
        }
    }

    visited[current] = false;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t q;
    cin >> q;
    for (size_t i = 0; i < q; i++) {
        size_t verticesCount, edgesCount;
        cin >> verticesCount >> edgesCount;

        vector<vector<Edge>> graph(verticesCount);

        for (size_t j = 0; j < edgesCount; j++) {
            size_t from, to, weight;
            cin >> from >> to >> weight;
            graph[from - 1].push_back({ to - 1, weight });
        }

        vector<bool> visited(verticesCount, false);

        bool flag = false;
        for (size_t j = 0; j < verticesCount; j++) {
            if (!visited[j]) {
                if (hasCycle(graph, visited, j)) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            cout << "true ";
        }
        else {
            cout << "false ";
        }
    }
    return 0;
}




