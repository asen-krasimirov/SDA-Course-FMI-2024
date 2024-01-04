#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int find(int v, int* parent) {
    if (v == parent[v]) {
        return v;
    }

    parent[v] = find(parent[v], parent);
    return parent[v];
}

void connect(int from, int to, int* parent) {
    int findX = find(from, parent);
    int findY = find(to, parent);
    parent[findX] = parent[findY];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    int parent[n+1];
    
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        connect(x, y, parent);
    }

    string result = "";

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int command, x, y;
        cin >> command >> x >> y;

        if (command == 1) {
            int findX = find(x, parent);
            int findY = find(y, parent);
            if (findX == findY) {
                result += '1';
            }
            else {
                result += '0';
            }
        }
        else if (command == 2) {
            connect(x, y, parent);
        }
    }
    cout << result;
    return 0;
}
