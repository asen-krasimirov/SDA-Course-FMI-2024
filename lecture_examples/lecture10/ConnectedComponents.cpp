#pragma once

#include <vector>

#include "Graph.cpp"

using namespace std;

class ConnectedComponents {

private:
    vector<bool> visited;
    vector<int> components;
    Graph &g;

    void dfs(int v, int component) {
        visited[v] = true;
        components[v] = component;

        for (int n: g.adj(v)) {
            if (!visited[n]) {
                dfs(n, component);
            }
        }
    }

    void separateComponents() {
        int currentComponent = 0;

        for (int i = 0; i < g.vertices(); ++i) {
            if (!visited[i]) {
                dfs(i, currentComponent);
                currentComponent++;
            }
        }
    }

public:
    ConnectedComponents(Graph &g) : g(g), components(g.vertices(), 0), visited(g.vertices()) {
        for (int i = 0; i < g.vertices(); ++i) {
            components[i] = i;
        }

        separateComponents();
    }

    bool areInSameComponent(int v, int n) {
        return components[v] == components[n];
    }

};