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

    Node *findSmallest(Node *node) {
        Node *current = node;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    Node *remove(int x, Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->val < x) {
            node->right = remove(x, node->right);
        } else if (node->val > x) {
            node->left = remove(x, node->left);
        } else {
            if (!node->left && !node->right) {
                return nullptr;
            }

            if (!node->left && node->right) {
                return node->right;
            }

            if (node->left && !node->right) {
                return node->left;
            }

            Node *smallestBigger = findSmallest(node->right);

            node->val = smallestBigger->val;

            node->right = remove(node->val, node->right);
        }

        return node;
    }

    void remove(int x) {
        root = remove(x, root);
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

    void print(int i, Node *node) {
        if (node == nullptr) {
            return;
        }

        if (i % 2 == 1) {
            cout << node->val << " ";
        }

        print(i + 1, node->left);
        print(i + 1, node->right);
    }

    void print_odd_layers() {
        print(1, root);
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
        } else if (cmd == "remove") {
            cin >> num;
            tree.remove(num);
        }
        else if (cmd == "print_odd_layers") {
            tree.print_odd_layers();
        }
    }

    return 0;
}
