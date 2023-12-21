#pragma once

#include <vector>

using namespace std;

struct WeightedEdge {
    int from, to, weight;
    WeightedEdge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};


class WeightedDirectedGraph {
    int numVertices;
    vector<WeightedEdge> *adjList;
public:
    WeightedDirectedGraph(int V): numVertices(V), adjList(new vector<WeightedEdge>[V]) {}
    ~WeightedDirectedGraph() {
        delete[] adjList;
    }

    void addEdge(WeightedEdge edge) { adjList[edge.from].push_back(edge);}

    vector<WeightedEdge> adj(int v) { return adjList[v];}

    int vertices() { return numVertices;}
};
