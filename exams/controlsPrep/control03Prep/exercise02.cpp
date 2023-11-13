/* HackerRank: https://www.hackerrank.com/contests/sda-test3-2022-2023-rdsafgtvh/challenges/challenge-3757 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    long long val;
    long long level, breadth;
    Node *left = nullptr, *right = nullptr;
    Node(long long val, long long level, long long breadth, Node *left = nullptr, Node *right = nullptr) : val(val), level(level), breadth(breadth), left(left), right(right) {};
};

struct BST {
private:
    long long maxLeftBreadth = 0, maxRightBreadth = 0;

    Node *root = nullptr;

    Node *insert(Node *cur, long long val, long long level, long long breadth) {
        if (cur == nullptr) {
            if (breadth < maxLeftBreadth) {
                maxLeftBreadth = breadth;
            } else if (breadth > maxRightBreadth) {
                maxRightBreadth = breadth;
            }

            return new Node(val, level, breadth);
        }

        if (val < cur->val) {
            cur->left = insert(cur->left, val, level + 1, breadth - 1);
        } else if (val > cur->val) {
            cur->right = insert(cur->right, val, level + 1, breadth + 1);
        }

        return cur;
    }

    void findSeenNodes(Node *cur, vector<Node *> &seen) {
        if (cur == nullptr) {
            return;
        }

        if (!seen[cur->breadth + maxLeftBreadth] || cur->level < seen[cur->breadth + maxLeftBreadth]->level) {
            seen[cur->breadth + maxLeftBreadth] = cur;
        }

        findSeenNodes(cur->left, seen);
        findSeenNodes(cur->right, seen);
    }

    void printSeen(vector<Node *> &seen) {
        for (Node *node : seen) {
            cout << node->val << " ";
        }
    }

public:
    void insert(long long val) {
        root = insert(root, val, 0, 0);
    }

    void customPrint() {
        maxLeftBreadth *= -1;
        vector<Node *> seenNodes(maxRightBreadth + maxLeftBreadth + 1);
        findSeenNodes(root, seenNodes);
        printSeen(seenNodes);
    }
};

int main() {
    long long T, N;
    cin >> T;

    for (long long i = 0; i < T; ++i) {
        cin >> N;

        BST bst;
        long long val;

        for (long long j = 0; j < N; ++j) {
            cin >> val;
            bst.insert(val);
        }

        bst.customPrint();
        cout << endl;
    }

    return 0;
}
