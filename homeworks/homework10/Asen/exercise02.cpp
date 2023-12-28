#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <climits>
#include <queue>

using namespace std;

int N, M, myGroup;
vector<int> *adjList;
vector<int> groups;
vector<int> distTo;

void addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

vector<int> adj(int v) {
    return adjList[v];
}

int shortestPath(int v) {
    queue<int> traversalOrder;
    traversalOrder.push(v);

    while (!traversalOrder.empty()) {
        int current = traversalOrder.front();
        traversalOrder.pop();

        for (int w : adj(current)) {
            if (distTo[w] == INT_MAX) {
                if (groups[w] == myGroup) {
                    return distTo[current] + 1;
                }

                distTo[w] = distTo[current] + 1;
                traversalOrder.push(w);
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    adjList = new vector<int>[N + 1];
    groups = vector<int>(N + 1);
    distTo = vector<int>(N + 1, INT_MAX);

    int v, w;
    for (int i = 0; i < M; i++) {
        cin >> v >> w;
        addEdge(v, w);
    }

    int group;
    for (int i = 1; i <= N; i++) {
        cin >> group;
        groups[i] = group;
    }

    cin >> myGroup;

    for (v = 1; v <= N; v++) {
        if (groups[v] == myGroup) {
            break;
        }
    }

    distTo[v] = 0;

    cout << shortestPath(v);

    return 0;
}
