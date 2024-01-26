#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

struct BST {
    Node *root = nullptr;

    void add(int x) {
        root = add(x, root);
    }

    void print() {
        print(root);
    }

private:
    Node *add(int x, Node *node) {
        if (!node) {
            return new Node(x);
        }

        if (node->val > x) {
            node->left = add(x, node->left);
        } else if (node->val < x) {
            node->right = add(x, node->right);
        }

        return node;
    }

    void print(Node *node) {
        if (!node) {
            return;
        }

        if (node->left && node->right) {
            cout << node->val << " ";
        }

        print(node->left);
        print(node->right);
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
