#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }


    void leaves(Node* root) {
        int sum = 0;
        dfs(root, sum);
        cout << sum;
    }
    void dfs(Node* node, int& sum) {
        if (!node) {
            return;
        }
        if ((!node->leftNode && !node->rightNode) && (node->data % 2 != 0)) {
            sum += node->data;
        }
        dfs(node->leftNode, sum);
        dfs(node->rightNode, sum);
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}