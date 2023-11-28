#include <iostream>

using namespace std;

struct Node {
    int val;
    unsigned height = 1;
    Node *left, *right;

    Node(int val, Node *left = nullptr, Node *right = nullptr) : val(val), left(left), right(right) {}
};

struct AVL {
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

        return balance(cur);
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

                return balance(right);
            } else if (cur->right == nullptr) {
                Node *left = cur->left;

                delete cur;

                return balance(left);
            } else {
                Node *temp = findSmallestValNodeRight(cur->right);

                cur->val = temp->val;

                cur->right = deleteNode(cur->right, temp->val);
            }
        }

        return balance(cur);
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

    /* AVL specific */

    int height(Node *n) {
        return n ? n->height : 0;
    }

    int bFactor(Node *n) {
        return height(n->left) - height(n->right);
    }

    void fixHeight(Node *n) {
        if (n == nullptr) {
            return;
        }

        unsigned hl = height(n->left);
        unsigned hr = height(n->right);
        n->height = (hl > hr ? hl : hr) + 1;
    }

    Node *rotateRight(Node *n) {
        Node *newN = n->left;
        n->left = newN->right;
        newN->right = n;

        fixHeight(n);
        fixHeight(newN);

        return newN;
    }

    Node *rotateLeft(Node *n) {
        Node *newN = n->right;
        n->right = newN->left;
        newN->left = n;

        fixHeight(n);
        fixHeight(newN);

        return newN;
    }

    Node *balance(Node *n) {
        if (n == nullptr) {
            return nullptr;
        }

        fixHeight(n);

        int balanceFactor = this->bFactor(n);

        if (balanceFactor == 2) {
            if (bFactor(n->left) > 0) {
                n->left = rotateLeft(n->left);
            }

            return rotateRight(n);
        } else if (balanceFactor == -2) {
            if (bFactor(n->right) > 0) {
                n->right = rotateRight(n->right);
            }

            return rotateLeft(n);
        }

        return n;
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

int main() {

    AVL avl;

    avl.insert(1);
    avl.insert(5);
    avl.insert(2);
    avl.insert(10);

    avl.deleteNode(5);
    avl.deleteNode(2);
    avl.deleteNode(11);

    avl.insert(6);

    avl.inorderPrint();

    return 0;
}
