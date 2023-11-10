#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    long long childCount;
    Node *left = nullptr, *right =nullptr, *parent = nullptr;
} nodes[1000000];

long long setChildCount(Node *current) {
    if (current == nullptr) {
        return 0;
    }

    current->childCount = setChildCount(current->left) + setChildCount(current->right) + 1;

    return current->childCount;
}

long long findBiggestSplit(Node *node) {
    if (!node->parent) {
        if (!node->left) {
            if (!node->right) {
                return 0;
            } else {
                return node->right->childCount;
            }
        } else if (!node->right) {
            return node->left->childCount;
        } else {
            return node->left->childCount * node->right->childCount;
        }
    }

    if (!node->left) {
        if (!node->right) {
            return nodes[0].childCount - 1;
        } else {
            return (nodes[0].childCount - node->childCount) * node->right->childCount;
        }
    } else {
        if (!node->right) {
            return (nodes[0].childCount - node->childCount) * node->left->childCount;
        }
    }

    if (node->left && node->right) {
        return (nodes[0].childCount - node->childCount) * node->left->childCount * node->right->childCount;
    }

    return 0;
}

int main() {
    long long N, leftIdx, rightIdx, biggestSplit = INT_MIN;

    cin >> N;

    for (long long i = 0; i < N; ++i) {
        cin >> leftIdx >> rightIdx;

        if (leftIdx != -1) {
            nodes[i].left = &nodes[leftIdx];
            nodes[i].left->parent = &nodes[i];
        } else {
            nodes[i].left = nullptr;
        }


        if (rightIdx != -1) {
            nodes[i].right = &nodes[rightIdx];
            nodes[i].right->parent = &nodes[i];
        } else {
            nodes[i].right = nullptr;
        }
    }

    setChildCount(&nodes[0]);

    for (long long i = 0; i < N; ++i) {
        biggestSplit = max(biggestSplit, findBiggestSplit(&nodes[i]));
    }

    cout << biggestSplit;

    return 0;
}
