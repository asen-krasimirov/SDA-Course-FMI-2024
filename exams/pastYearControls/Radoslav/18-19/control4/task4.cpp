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


    void count(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<int> v;
        while (!q.empty()) {
            int size = q.size();
            v.push_back(size);
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr->leftNode) {
                    q.push(curr->leftNode);
                }
                if (curr->rightNode) {
                    q.push(curr->rightNode);
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1) {
                cout << ";";
            }
        }
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

    myTree.count(root);
    return 0;
}