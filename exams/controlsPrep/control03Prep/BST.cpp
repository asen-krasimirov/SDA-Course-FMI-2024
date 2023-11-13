#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int val, Node *left = nullptr, Node *right = nullptr) : val(val), left(left), right(right) {}
};

struct BST {
private:
    Node *root = nullptr;

    Node *insert(Node *cur, int val) {
        if (cur == nullptr) {
            return new Node(val);
        }

        if (val > cur->val) {
            cur->right = insert(cur->right, val);
        } else if (val < cur->val) {
            cur->left = insert(cur->left, val);
        }

        return cur;
    }

    Node *findSmallestValNodeRight(Node *cur) {
        Node *current = cur;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    Node *deleteNode(Node *cur, int val) {
        if (cur == nullptr) {
            return cur;
        }

        if (val > cur->val) {
            cur->right = deleteNode(cur->right, val);
        } else if (val < cur->val) {
            cur->left = deleteNode(cur->left, val);
        } else {
            if (cur->left == nullptr) {
                Node *right = cur->right;

                delete cur;

                return right;
            } else if (cur->right == nullptr) {
                Node *left = cur->left;

                delete cur;

                return left;
            } else {
                Node *temp = findSmallestValNodeRight(cur->right);

                cur->val = temp->val;

                cur->right = deleteNode(cur->right, temp->val);
            }
        }

        return cur;
    }

    void inorderPrint(Node *cur) {
        if (cur == nullptr) {
            return;
        }

        inorderPrint(cur->left);
        cout << cur->val << " ";
        inorderPrint(cur->right);
    }

    Node *search(Node *cur, int val) {
        if (cur == nullptr) {
            return nullptr;
        }

        if (val < cur->val) {
            return search(cur->left, val);
        } else if (val > cur->val) {
            return search(cur->right, val);
        } else {
            return cur;
        }
    }

public:
    void insert(int val) {
        root = insert(root, val);
    }

    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    void inorderPrint() {
        inorderPrint(root);
    }

    Node *search(int val) {
        return search(root, val);
    }

};