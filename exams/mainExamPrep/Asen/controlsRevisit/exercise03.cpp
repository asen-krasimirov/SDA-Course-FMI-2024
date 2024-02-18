#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    vector<Node *> nodes;

    int getAll() {
        int ctr = 0;

        for (auto n : nodes) {
            ctr += n->getAll() + 1;
        }

        return ctr;
    }
} arr[10000001];

int main() {
    int N, x, y;
    cin >> N;

    while (cin >> x >> y) {
        arr[x].nodes.push_back(&arr[y]);
    }

    for (int i = 0; i < N; ++i) {
        cout << arr[i].getAll() << " ";
    }

    return 0;
}
