#pragma once

#include <vector>
#include <stack>

#include "Graph.cpp"

using namespace std;

class CycleInDirectedGraph {

private:
    vector<bool> visited;
    Graph &g;

    bool dfs(int v, vector<bool> &recStack) {
        if (recStack[v]) {
            return true;
        }

        if (visited[v]) {
            return false;
        }

        recStack[v] = true;

        for (int n : g.adj(v)) {
            if (dfs(n, recStack)) {
                return true;
            }
        }

        recStack[v] = false;
        return false;

    }

public:
    CycleInDirectedGraph(Graph &g) : g(g), visited(g.vertices()) {}

    bool hasCycle() {
        vector<bool> recStack(g.vertices());

        for (int i = 0; i < g.vertices(); ++i) {
            if (!visited[i]) {
                if (dfs(i, recStack)) {
                    return true;
                }
            }
        }

        return false;
    }

};