#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
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

    void printSFB(int k) {
        Node* start = root;
        queue<Node*> q;
        q.push(start);
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            if (count == k) {
                for (int i = 0; i < size; i++) {
                    Node* curr = q.front();
                    q.pop();
                    cout << curr->value << ' ';
                    if (curr->right) {
                        q.push(curr->right);
                    }
                    if (curr->left) {
                        q.push(curr->left);
                    }
                }
                break;
            }
            else {
                for (int i = 0; i < size; i++) {
                    Node* curr = q.front();
                    q.pop();
                    if (curr->right) {
                        q.push(curr->right);
                    }
                    if (curr->left) {
                        q.push(curr->left);
                    }
                }
            }
            count++;
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
    int k;
    cin >> k;
    tree.printSFB(k);
    return 0;
}