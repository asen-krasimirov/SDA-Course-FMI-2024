#pragma once

#include <iostream>
#include <vector>
#include <stack>

#include "Graph.cpp"

using namespace std;

class TopologicalSort {

private:
    vector<bool> visited;
    stack<int> topoOrder;
    Graph &g;

    void dfs(int v) {
        visited[v] = true;

        for (int n : g.adj(v)) {
            if (!visited[n]) {
                dfs(n);
            }
        }

        topoOrder.push(v);
    }

public:
    TopologicalSort(Graph &g) : g(g), visited(g.vertices()) {
        for (int i = 0; i < g.vertices(); ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

    void printInTopologicalOrder() {
        while (!topoOrder.empty()) {
            cout << topoOrder.top();
            topoOrder.pop();

            if (topoOrder.size() > 0) {
                cout << " -> ";
            }
        }
    }
};