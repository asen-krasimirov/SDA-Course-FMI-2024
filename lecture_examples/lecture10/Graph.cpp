#pragma once

#include <vector>

using namespace std;

class Graph {

private:
    int numVertices;
    vector<int> *adjList;
    bool directed;

public:
    Graph(int V, bool directed) : numVertices(V), adjList(new vector<int>[V]), directed(directed) {}

    void addEdge(int v, int w) {
        if (!directed) {
            adjList[w].push_back(v);
        }
        adjList[v].push_back(w);
    }

    vector<int> adj(int v) {
        return adjList[v];
    }

    int vertices() {
        return numVertices;
    }

};
