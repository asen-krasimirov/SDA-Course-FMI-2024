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



    void print(Node* root) {
        vector<int> v;
        dfs(root, v);
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1) {
                cout << ";";
            }
        }
    }
    void dfs(Node* root, vector<int>& v) {
        if (!root) {
            return;
        }
        dfs(root->rightNode, v);
        dfs(root->leftNode, v);
        v.push_back(root->data);
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

    myTree.print(root);
    return 0;
}