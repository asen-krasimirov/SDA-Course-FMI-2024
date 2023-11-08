#include <iostream>

using namespace std;

struct Node {

    int value;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int value, Node *left = nullptr, Node *right = nullptr) : value(value), left(left), right(nullptr) {}

};

class BinarySearchTree {

private:
    Node *root = nullptr;

    Node *insert(Node *node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value > node->value) {
            node->right = insert(node->right, value);
        } else if (value < node->value) {
            node->left = insert(node->left, value);
        } else {

        }

        return node;
    }

    Node *findMinValueNode(Node *node) {
        Node *current = node;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    Node *remove(Node *node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value > node->value) {
            node->right = remove(node->right, value);
        } else if (value < node->value) {
            node->left = remove(node->left, value);
        } else {
            if (node->left == nullptr) {
                Node *temp = node->right;

                delete node;

                return temp;
            } else if (node->right == nullptr) {
                Node *temp = node->left;

                delete node;

                return temp;
            } else {
                Node *temp = findMinValueNode(node->right);         // or findMinValueNode(node->left);

                node->value = temp->value;

                node->right = remove(node->right, temp->value);     // or deleteNode(node->left, temp->value);
            }
        }

        return node;
    }

    void inorder(const Node *current) {
        if (current == nullptr) {
            return;
        }

        inorder(current->left);
        cout << current->value << endl;
        inorder(current->right);
    }


public:
    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void print() {
        inorder(root);
    }

};


int main() {
    BinarySearchTree binarySearchTree;
    binarySearchTree.insert(5);
    binarySearchTree.insert(2);
    binarySearchTree.insert(10);

    binarySearchTree.print();
    cout << " ";
    binarySearchTree.remove(2);
    binarySearchTree.print();

    return 0;
}