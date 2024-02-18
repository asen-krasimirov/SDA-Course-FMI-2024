#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int to, weight;
};

unordered_map<size_t, vector<Node>> graph;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to,weight });
        graph[to].push_back({ from,weight });
    }

    int q;
    cin >> q;
    vector<int> nodes;
    for (int i = 0; i < q; i++) {
        int node;
        cin >> node;
        nodes.push_back(node);
    }

    int result = 0;
    bool flag = false;
    for (int i = 0; i < q - 1; i++) {
        int current = nodes[i];
        for (auto& n : graph[current]) {
            if (n.to == nodes[i + 1]) {
                flag = true;
                result += n.weight;
            }
        }
        if (!flag) {
            break;
        }
    }

    if (!flag) {
        cout << -1;
    }
    else {
        cout << result;
    }

    return 0;
}



