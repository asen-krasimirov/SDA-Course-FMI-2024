#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* 70/100 */

struct Node {
    int val = -1;
    int breadth;
    int leftIdx, rightIdx;
    Node *left, *right;
} nodes[1000000];

int N, curVal, leftIdx, rightIdx, mostLeftBreadth = 0, mostRightBreadth = 0;

void inorderSumUp(Node *current, vector<int> &columnSums) {
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
        nodes[0].leftIdx = leftIdx;
        nodes[0].left = &nodes[leftIdx];
        nodes[0].left->breadth = -1;
    } else {
        nodes[0].left = nullptr;
    }

    if (rightIdx != -1) {
        nodes[0].rightIdx = rightIdx;
        nodes[0].right = &nodes[rightIdx];
        nodes[0].right->breadth = 1;
    } else {
        nodes[0].right = nullptr;
    }

    Node *current = &nodes[0];

    for (int nextCtr = 1, i = 1; nextCtr < N; ++nextCtr) {
        if (current->leftIdx != nextCtr && current->rightIdx != nextCtr) {
            if (current->leftIdx != -1) {
                i = current->leftIdx;
            } else if (current->rightIdx != -1) {
                i = current->rightIdx;
            } else {
                i = nextCtr;
            }
        } else {
            i = nextCtr;
        }

        cin >> curVal >> leftIdx >> rightIdx;

        nodes[i].val = curVal;

        if (leftIdx != -1) {
            nodes[i].leftIdx = leftIdx;
            nodes[i].left = &nodes[leftIdx];
            nodes[i].left->breadth = nodes[i].breadth - 1;
            if (nodes[i].left->breadth < mostLeftBreadth) {
                mostLeftBreadth = nodes[i].left->breadth;
            }
        } else {
            nodes[i].left = nullptr;
        }

        if (rightIdx != -1) {
            nodes[i].rightIdx = rightIdx;
            nodes[i].right = &nodes[rightIdx];
            nodes[i].right->breadth = nodes[i].breadth + 1;
            if (nodes[i].right->breadth > mostRightBreadth) {
                mostRightBreadth = nodes[i].right->breadth;
            }
        } else {
            nodes[i].right = nullptr;
        }

        current = &nodes[i];
    }

    mostLeftBreadth *= -1;

    vector<int> columnSums(mostRightBreadth + mostLeftBreadth + 1, 0);

//    for (int i = 0; i < 1000000; ++i) {
    inorderSumUp(&nodes[0], columnSums);
//    }

    for (auto columnSum : columnSums) {
        cout << columnSum << " ";
    }

    return 0;
}
