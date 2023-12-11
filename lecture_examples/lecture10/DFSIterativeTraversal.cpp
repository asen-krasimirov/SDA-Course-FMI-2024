#pragma once

#include <vector>
#include <stack>
#include "Graph.cpp"

using namespace std;

class DFSIterativeTraversal {

private:
    vector<bool> visited;
    Graph &g;

public:
    DFSIterativeTraversal(Graph &g) : g(g), visited(g.vertices()) {}

    void dfs(int v) {
        stack<int> recStack;
        recStack.push(v);
        visited[v] = true;

        while(!recStack.empty()) {
            v = recStack.top();
            recStack.pop();

            if (!visited[v]) {
                visited[v] = true;

                for (int n : g.adj(v)) {
                    if (!visited[n]) {
                        recStack.push(n);
                    }
                }
            }
        }
    }

};
