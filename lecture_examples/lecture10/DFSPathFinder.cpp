#pragma once

#include <iostream>
#include <vector>
#include <stack>

#include "Graph.cpp"

using namespace std;

class DFSPathFinder {

private:
    vector<bool> visited;
    vector<int> pathTo;
    Graph &g;

    void dfs(int v) {
        visited[v] = true;

        for (int n : g.adj(v)) {
            if (!visited[n]) {
                pathTo[n] = v;
                dfs(n);
            }
        }
    }

public:
    DFSPathFinder(Graph &g, int v) : g(g), visited(g.vertices()), pathTo(g.vertices()) {
        for (int i = 0; i < g.vertices(); ++i) {
            pathTo[i] = i;
        }

        dfs(v); // paths start from v
    }

    void printPathTo(int v) {
        stack<int> path;

        while (true) {
            path.push(v);
            v = pathTo[v];

            if (v == pathTo[v]) {
                path.push(v);
                break;
            }
        }

        while (!path.empty()) {
            cout << path.top();
            path.pop();

            if (path.size() > 0) {
                cout << " -> ";
            }
        }

        cout << endl;
    }

};