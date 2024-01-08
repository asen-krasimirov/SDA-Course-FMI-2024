#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include<unordered_set>
#include <algorithm>
using namespace std;

struct Node {
    int to, weight;
};

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<Node>> graph;
    unordered_set<int> numbers;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to,weight });
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        numbers.insert(num);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l;
        cin >> l;
        bool flag = false;
        vector<int> nodes;
        for (int j = 0; j < l; j++) {
            int node;
            cin >> node;
            nodes.push_back(node);
        }

        for (int j = 0; j < l - 1; j++) {
            int from = nodes[j];
            int to = nodes[j + 1];
            flag = false;
            for (auto& el : graph[from]) {
                if (numbers.find(el.weight) == numbers.end() && el.to == to) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                break;
        }
        cout << flag;
    }
    return 0;
}