/* HackerRank: https://www.hackerrank.com/contests/sda-test3-2022-2023-rdsafgtvh/challenges/--149/problem */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    long long val;
    Node *left = nullptr, *right = nullptr;
    Node(long long val, Node *left = nullptr, Node *right = nullptr) : val(val), left(left), right(right) {};
};

struct BST {
private:
    Node *root = nullptr;

    Node *insert(Node *cur, long long val) {
        if (cur == nullptr) {
            return new Node(val);
        }

        if (val < cur->val) {
            cur->left = insert(cur->left, val);
        } else if (val > cur->val) {
            cur->right = insert(cur->right, val);
        }

        return cur;
    }

    void customPrint(Node *cur) {
        if (cur == nullptr) {
            return;
        }

        if (cur->left != nullptr && cur->right != nullptr) {
            cout << cur-> val << " ";
        }

        customPrint(cur->left);
        customPrint(cur->right);
    }

public:
    void insert(long long val) {
        root = insert(root, val);
    }

    void customPrint() {
        customPrint(root);
    }

};

int main() {
    long long T, N;
    cin >> T;

    for (long long i = 0; i < T; ++i) {
        cin >> N;

        BST bst;
        long long val;

        for (long long j = 0; j < N; ++j) {
            cin >> val;
            bst.insert(val);
        }

        bst.customPrint();
        cout << endl;
    }

    return 0;
}
