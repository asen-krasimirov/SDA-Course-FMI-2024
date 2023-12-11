#include <iostream>

#include "Graph.cpp"
#include "DFSRecursiveTraversal.cpp"
#include "BFSTraversal.cpp"

#include "DFSPathFinder.cpp"

#include "BFSShortestPathFinder.cpp"

int main() {

    Graph g(7, false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

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

    return 0;
}