#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void deletePenultimateAndPrint() {
        dfs(root);
    }

private:
    Node* findMax(Node* node) {
        if (root->right != NULL)
        {
            return findMax(root->right);
        }
        return root;
    }
    void dfs(Node* node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left);
        if (!(node->left || node->right)) {
            cout << node->value << ' ';
        }
        else {
            bool one = true, two = true;
            if (node->left) {
                if (node->left->left || node->left->right) {
                    one = false;
                }
            }
            if (node->right) {
                if (node->right->left || node->right->right) {
                    two = false;
                }
            }
            if (!(one && two)) {
                cout << node->value << ' ';
            }
        }
        dfs(node->right);
    }
    Node* root;

    Node* insert(Node* curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        }
        else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        }
        else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.deletePenultimateAndPrint();
    return 0;
}