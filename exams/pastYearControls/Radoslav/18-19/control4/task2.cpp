#include <bits/stdc++.h>

using namespace std;
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


    void leftRight(Node* root) {
        int l = 0, r = 0;
        dfs(root, l, r);
        cout << "[" << l << "," << r << "]";
    }

    void dfs(Node* node, int& l, int& r) {
        if (!node) {
            return;
        }
        if (node->leftNode) {
            l++;
        }
        if (node->rightNode) {
            r++;
        }
        dfs(node->leftNode, l, r);
        dfs(node->rightNode, l, r);
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

    myTree.leftRight(root);
    return 0;
}