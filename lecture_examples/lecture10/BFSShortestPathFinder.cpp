#pragma once

#include <iostream>
#include <queue>
#include <limits.h>

#include "Graph.cpp"

class BFSShortestPathFinder {

private:
    Graph &g;
    vector<int> distTo;

public:
    BFSShortestPathFinder(Graph &g, int v) : g(g) , distTo(g.vertices(), INT_MAX) {
        distTo[0] = v;

        pathsFrom(v);
    }

    void pathsFrom(int v) {
        queue<int> q;
        q.push(v);

        while (!q.empty()) {
            v = q.front();
            q.pop();

            for (int n : g.adj(v)) {
                if (distTo[n] == INT_MAX) {
                    distTo[n] = distTo[v] + 1;
                    q.push(n);
                }
            }
        }
    }

    int getMinDist(int n) {
        return distTo[n];
    }

};