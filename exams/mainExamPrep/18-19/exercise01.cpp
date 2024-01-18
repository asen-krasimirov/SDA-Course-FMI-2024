#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int a) : val(a), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node *root = nullptr;

    Node *createNode(int a, Node *node) {
        if (node == nullptr) {
            return new Node(a);
        }

        if (node->val < a) {
            node->right = createNode(a, node->right);
        } else if (node->val > a) {
            node->left = createNode(a, node->left);
        }
        return node;
    }

    void add(int x) {
        root = createNode(x, root);
    }

    void print(Node *node) {
        if (node == nullptr) {
            return;
        }

        cout << node->val << " ";
        print(node->left);
        print(node->right);
    }

    void print() {
        print(root);
    }
};

int main() {

    int Q, num;
    string cmd;

    Tree tree;

    cin >> Q;

    while (Q--) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> num;

            tree.add(num);
        } else if (cmd == "print") {
            tree.print();
        }
    }

    return 0;
}
