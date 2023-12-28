#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long maxPath = INT_MIN;

struct Node {
    long long val;
    Node *left, *right;
} nodes[4000001];

long long findMaxPath(Node *node) {
    if (node == nullptr) {
        return 0;
    }

    long long maxLeft = max((long long) 0, findMaxPath(node->left));
    long long maxRight = max((long long) 0, findMaxPath(node->right));

    maxPath = max(maxPath, node->val + maxLeft + maxRight);

    return node->val + max(maxLeft, maxRight);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, val, leftIdx, rightIdx;
    cin >> N;

    for (long long i = 0; i < N; ++i) {
        cin >> val >> leftIdx >> rightIdx;

        nodes[i].val = val;

        if (leftIdx != -1) {
            nodes[i].left = &nodes[leftIdx];
        } else {
            nodes[i].left = nullptr;
        }

        if (rightIdx != -1) {
            nodes[i].right = &nodes[rightIdx];
        } else {
            nodes[i].right = nullptr;
        }
    }

    findMaxPath(&nodes[0]);

    cout << maxPath;

    return 0;
}
