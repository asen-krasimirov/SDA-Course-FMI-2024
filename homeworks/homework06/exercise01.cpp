#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    long long val;
    long long breadth;
    Node *left, *right;
} nodes[1000000];

long long N, curVal, leftIdx, rightIdx, mostLeftBreadth = 0, mostRightBreadth = 0;

void inorderSumUp(Node *current, vector<long long> &columnSums) {
    if (current == nullptr) {
        return;
    }

    inorderSumUp(current->left, columnSums);
    columnSums[current->breadth + mostLeftBreadth] += current->val;
    inorderSumUp(current->right, columnSums);
}

int main() {
    cin >> N >> curVal >> leftIdx >> rightIdx;

    nodes[0].val = curVal;

    nodes[0].breadth = 0;

    if (leftIdx != -1) {
        nodes[0].left = &nodes[leftIdx];
        nodes[0].left->breadth = -1;
    } else {
        nodes[0].left = nullptr;
    }

    if (rightIdx != -1) {
        nodes[0].right = &nodes[rightIdx];
        nodes[0].right->breadth = 1;
    } else {
        nodes[0].right = nullptr;
    }

    for (long long i = 1; i < N; ++i) {
        cin >> curVal >> leftIdx >> rightIdx;

        nodes[i].val = curVal;

        if (leftIdx != -1) {
            nodes[i].left = &nodes[leftIdx];
            nodes[i].left->breadth = nodes[i].breadth - 1;
            if (nodes[i].left->breadth < mostLeftBreadth) {
                mostLeftBreadth = nodes[i].left->breadth;
            }
        } else {
            nodes[i].left = nullptr;
        }

        if (rightIdx != -1) {
            nodes[i].right = &nodes[rightIdx];
            nodes[i].right->breadth = nodes[i].breadth + 1;
            if (nodes[i].right->breadth > mostRightBreadth) {
                mostRightBreadth = nodes[i].right->breadth;
            }
        } else {
            nodes[i].right = nullptr;
        }
    }

    mostLeftBreadth *= -1;

    vector<long long> columnSums(mostRightBreadth + mostLeftBreadth + 1, 0);

    inorderSumUp(&nodes[0], columnSums);

    for (auto columnSum : columnSums) {
        cout << columnSum << " ";
    }

    return 0;
}
