/* HackerRank: https://www.hackerrank.com/contests/sda-2021-2021-test-3-november16/challenges/challenge-1692/problem */

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *leftNode;
    Node *rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            } else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }

    void countLeaves(Node *cur, long long &res) {
        if (cur == nullptr) {
            return;
        }

        if (cur->leftNode == nullptr && cur->rightNode == nullptr && cur->data % 2 != 0) {
            res += cur->data;
        } else {
            countLeaves(cur->leftNode, res);
            countLeaves(cur->rightNode, res);
        }
    }

    void leaves(Node *root) {
        long long res = 0;
        countLeaves(root, res);
        cout << res;
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}