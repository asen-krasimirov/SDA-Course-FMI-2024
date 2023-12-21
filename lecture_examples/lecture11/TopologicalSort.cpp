#pragma once

#include <iostream>
#include <vector>
#include <stack>

#include "WeightedDirectedGraph.cpp"

using namespace std;

class TopologicalSort {

private:
    vector<bool> visited;
    stack<int> topoOrder;
    WeightedDirectedGraph &g;

    void dfs(int v) {
        visited[v] = true;

        for (auto n : g.adj(v)) {
            if (!visited[n.to]) {
                dfs(n.to);
            }
        }

        topoOrder.push(v);
    }

public:
    TopologicalSort(WeightedDirectedGraph &g) : g(g), visited(g.vertices()) {
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

    stack<int>& getTopoOrder() {
        return topoOrder;
    }
};