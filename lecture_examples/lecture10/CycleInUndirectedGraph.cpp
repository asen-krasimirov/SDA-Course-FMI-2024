#pragma once

#include <vector>

#include "Graph.cpp"

using namespace std;

class CycleInUndirectedGraph {

private:
    vector<bool> visited;
    Graph &g;

    bool dfs(int v, int s) {
        visited[v] = true;

        for (int n : g.adj(v)) {
            if (visited[n] && n != s) {
                return true;
            }

            if (!visited[n]) {
                if(dfs(n, v)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    CycleInUndirectedGraph(Graph &g) : g(g), visited(g.vertices()) {}

    bool hasCycle() {
        for (int i = 0; i < g.vertices(); ++i) {
            if (!visited[i]) {
                if (dfs(i, -1)) {
                    return true;
                }
            }
        }

        return false;
    }

};