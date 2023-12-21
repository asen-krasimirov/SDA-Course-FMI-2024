#include <climits>
#include <queue>

#include "WeightedDirectedGraph.cpp"
#include "TopologicalSort.cpp"

using namespace std;

class ShortestPath {
private:
    WeightedDirectedGraph graph;
    int *distTo;
    int *edgeTo;

    bool relax(WeightedEdge e) {
        int v = e.from;
        int u = e.to;

        int currentDistance = distTo[v] = e.weight;

        if (currentDistance < distTo[u]) {
            distTo[u] = currentDistance;
            edgeTo[u] = v;
            return true;
        }

        return false;
    }

    void resetDistances() {
        for (int i = 0; i < graph.vertices(); i++) {
            distTo[i] = INT_MAX;
            edgeTo[i] = i;
        }
    }

public:
    ShortestPath(WeightedDirectedGraph graph, int from) : graph(graph) {
        distTo = new int[graph.vertices()];
        edgeTo = new int[graph.vertices()];

        resetDistances();

        distTo[from] = 0;
    }

    void dijkstra(int start) {
        resetDistances();   // optional

        vector<bool> visited(graph.vertices());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        queue.push({ 0, start });

        while(!queue.empty()) {
            int v = queue.top().second;
            queue.pop();

            if (visited[v]) {
                continue;
            }

            visited[v] = true;

            for (auto edge : graph.adj(v)) {
                if (relax(edge)) {
                    queue.push({ distTo[edge.to], edge.to });
                }
            }
        }
    }

    void bellman_ford(int start) {
        resetDistances();   // optional

        distTo[start] = 0;

        for (int i = 0; i < graph.vertices() - 1; ++i) {
            for (int v = 0; v < graph.vertices(); ++v) {
                if (distTo[v] != INT_MAX) {
                    for (auto edge : graph.adj(v)) {
                        relax(edge);
                    }
                }
            }
        }
    }

    bool hasNegativeCycle() {
        bellman_ford(0);

        for (int v = 0; v < graph.vertices(); ++v) {
            for (auto edge : graph.adj(v)) {
                if (relax(edge)) {
                    return true;
                }
            }
        }

        return false;
    }

    void dag_shortest_path() {
        TopologicalSort topologicalSort = TopologicalSort(graph);
        stack<int> topoOrder = topologicalSort.getTopoOrder();

        while (!topoOrder.empty()) {
            int v = topoOrder.top();
            topoOrder.pop();

            for (auto edge : graph.adj(v)) {
                relax(edge);
            }
        }
    }
};
