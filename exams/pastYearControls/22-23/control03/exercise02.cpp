#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    int b;
    int l;

    Node *left;
    Node *right;

    Node(int val, int b, int l) : val(val), b(b), l(l), left(nullptr), right(nullptr) {}
};

struct BST {
    Node *root = nullptr;
    int leftBreadth = 0;
    int rightBreadth = 0;
    int totalB = 0;

    void add(int x) {
        root = add(x, root, 0, 0);
    }

    void print() {
        leftBreadth *= -1;
        totalB = leftBreadth + rightBreadth + 1;

        vector<Node *> taken(totalB);
        findNodes(root, taken);

        for (auto node : taken) {
            cout << node->val << " ";
        }
    }

private:
    Node *add(int x, Node *node, int breadth, int level) {
        if (!node) {
            leftBreadth = min(leftBreadth, breadth);
            rightBreadth = max(rightBreadth, breadth);

            return new Node(x, breadth, level);
        }

        if (node->val > x) {
            node->left = add(x, node->left, --breadth, ++level);
        } else if (node->val < x) {
            node->right = add(x, node->right, ++breadth, ++level);
        }

        return node;
    }

    void findNodes(Node *node, vector<Node *> &taken) {
        if (!node) {
            return;
        }

        if (!taken[node->b + leftBreadth] || node->l < taken[node->b + leftBreadth]->l) {
            taken[node->b + leftBreadth] = node;
        }

        findNodes(node->left, taken);
        findNodes(node->right, taken);
    }
};

int main() {
    int T, N, x;
    cin >> T;

    while (T--) {
        BST bst;

        cin >> N;

        while (N--) {
            cin >> x;

            bst.add(x);
        }

        bst.print();
        cout << endl;
    }

    return 0;
}
