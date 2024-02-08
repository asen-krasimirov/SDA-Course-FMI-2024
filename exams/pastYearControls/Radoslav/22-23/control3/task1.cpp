#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (node->value < value) {
        node->right = insert(node->right, value);
    }
    else if (node->value > value) {
        node->left = insert(node->left, value);
    }
    return node;
}
void print(Node* node) {
    if (node == nullptr) {
        return;
    }
    if (node->left && node->right) {
        cout << node->value << ' ';
    }
    print(node->left);
    print(node->right);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        Node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            root = insert(root, value);
        }
        print(root);
        cout << '\n';
    }
    return 0;
}