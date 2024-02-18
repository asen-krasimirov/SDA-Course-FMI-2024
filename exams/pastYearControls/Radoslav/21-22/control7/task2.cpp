#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Node {
    int to, weight;
};

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<Node>> graph;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to,weight });
    }
    unordered_set<int> numbers;
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
        vector<int> path(l);
        for (int j = 0; j < l; j++) {
            cin >> path[j];
        }
        bool flag = false;
        for (int j = 0; j < l - 1; j++) {
            int from = path[j];
            int to = path[j + 1];
            flag = false;
            for (auto& sused : graph[from]) {
                if (numbers.find(sused.weight) == numbers.end() && sused.to == to) {
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


