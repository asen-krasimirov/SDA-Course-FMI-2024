#pragma once

#include <iostream>
#include <vector>
#include "Graph.cpp"

using namespace std;

class DFSRecursiveTraversal {

private:
    vector<bool> visited;
    Graph &g;

public:
    DFSRecursiveTraversal(Graph &g) : g(g), visited(g.vertices()) {}

    void dfs(int v) {
        visited[v] = true;

        for (int n : g.adj(v)) {
            if (!visited[n]) {
                dfs(n);
            }
        }
    }

};
