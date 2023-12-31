#include <iostream>

#include "Graph.cpp"
#include "DFSRecursiveTraversal.cpp"
#include "BFSTraversal.cpp"

#include "DFSPathFinder.cpp"

#include "BFSShortestPathFinder.cpp"

#include "ConnectedComponents.cpp"

#include "CycleInUndirectedGraph.cpp"

#include "CycleInDirectedGraph.cpp"

#include "TopologicalSort.cpp"

int main() {

    Graph g(9, false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(7, 8);

//    cout << "DFS: " << endl;
//    DFSRecursiveTraversal dfs(g);
//    dfs.dfs(0);
//
//    cout << endl;
//
//    cout << "BFS: " << endl;
//    BFSTraversal bfs(g);
//    bfs.bfs(0);

    cout << endl;

    cout << "PathFinder:" << endl;
    DFSPathFinder pathFinder(g, 0); // starts from 0
    pathFinder.printPathTo(6);      // 0 -> 1 -> 2 -> 4 -> 5 -> 6

    cout << endl;

    cout << "Shortest Path:" << endl;
    BFSShortestPathFinder shortestPathFinder(g, 0);
    cout << shortestPathFinder.getMinDist(6);

    cout << endl;

    cout << "Connected Components:" << endl;
    ConnectedComponents connectedComponents(g);
    cout << connectedComponents.areInSameComponent(0, 1) << endl;
    cout << connectedComponents.areInSameComponent(7, 8) << endl;
    cout << connectedComponents.areInSameComponent(0, 8) << endl;

    cout << endl;

    cout << "Cycle in undirected graph:" << endl;
    Graph g1(3, false);
    g1.addEdge(0, 1);

    CycleInUndirectedGraph cycleInUndirectedGraph(g);
    CycleInUndirectedGraph cycleInUndirectedGraph1(g1);
    cout << cycleInUndirectedGraph.hasCycle() << endl;
    cout << cycleInUndirectedGraph1.hasCycle() << endl;

    cout << endl;

    cout << "Cycle in undirected graph:" << endl;
    Graph g2(4, true);
    g2.addEdge(0, 1);
    g2.addEdge(1, 3);
    g2.addEdge(3, 2);
    g2.addEdge(2, 1);

    CycleInDirectedGraph cycleInDirectedGraph(g2);
    cout << cycleInDirectedGraph.hasCycle() << endl;

    cout << endl;

    cout << "Topological Sort:" << endl;
    Graph g3(7, true);
    g3.addEdge(0, 1);
    g3.addEdge(0, 2);
    g3.addEdge(1, 2);
    g3.addEdge(1, 5);
    g3.addEdge(6, 1);
    g3.addEdge(6, 5);
    g3.addEdge(5, 3);
    g3.addEdge(2, 3);
    g3.addEdge(5, 4);

    TopologicalSort topologicalSort(g3);
    topologicalSort.printInTopologicalOrder();

    cout << endl;

    return 0;
}