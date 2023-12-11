#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "Graph.cpp"

using namespace std;

class BFSTraversal {

private:
    vector<bool> visited;
    Graph &g;

public:
    BFSTraversal(Graph &g) : g(g), visited(g.vertices()) {}

    void bfs(int v) {
        queue<int> q;
        q.push(v);
        visited[v] = true;

        while (!q.empty()) {
            v = q.front();
            q.pop();

            for (int n : g.adj(v)) {
                if (!visited[n]) {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
    }

};