#include <cmath>
#include <cstdio>
#include <deque>
#include <queue>
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

    void printSFB() {
        deque<Node*> q;
        q.push_back(root);
        bool flag = true;
        while (!q.empty()) {
            int size = q.size();
            if (!flag) {
                for (int i = 0; i < size; i++) {
                    Node* curr = q.back();
                    std::cout << curr->value << " ";
                    q.pop_back();
                    if (curr->right) {
                        q.push_front(curr->right);
                    }
                    if (curr->left) {
                        q.push_front(curr->left);
                    }
                }
                flag = true;
            }
            else {
                for (int i = 0; i < size; i++) {
                    Node* curr = q.front();
                    std::cout << curr->value << " ";
                    q.pop_front();
                    if (curr->left) {
                        q.push_back(curr->left);
                    }
                    if (curr->right) {
                        q.push_back(curr->right);
                    }
                }
                flag = false;
            }
        }
    }

private:
    //you can write helper functions if needed
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

    tree.printSFB();
    return 0;
}