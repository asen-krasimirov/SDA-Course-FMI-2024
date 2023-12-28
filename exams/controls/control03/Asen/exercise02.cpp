#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    vector<Node *> nodes;

    long long getNodesCount() {
        long long size = nodes.size();
        long long count = size;

        for (long long i = 0; i < size; ++i) {
            count += nodes[i]->getNodesCount();
        }

        return count;
    }

} nodes[1000001];

int main() {
    long long N, parentIdx, childIdx;
    cin >> N;

    while (cin >> parentIdx >> childIdx) {
        nodes[parentIdx].nodes.push_back(&nodes[childIdx]);
    }

    for (long long i = 0; i < N; ++i) {
        cout << nodes[i].getNodesCount() << " ";
    }

    return 0;
}
