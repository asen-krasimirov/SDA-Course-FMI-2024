/* HackerRank: https://www.hackerrank.com/contests/sda-2021-2021-test-3-november16/challenges/tree-specific-print/problem */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int value;
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{

public:
    BST(){
        root = NULL;
    }
    void insert(int value){
        root = insert(root, value);
    }

    void printSpecific(int dividedBy){
        // TODO implement this function
        customPrint(root, dividedBy);
    }

private:
    // you can implemented helper functions if you want
    void customPrint(Node *cur, int dividedBy) {
        if (cur == nullptr) {
            return;
        }

        if (cur->value % dividedBy == 0 && (cur->left != nullptr || cur->right != nullptr)) {
            cout << cur->value << " ";
        }

        customPrint(cur->left, dividedBy);
        customPrint(cur->right, dividedBy);
    }

    Node* root;

    Node* insert(Node *curNode, int value){
        if(curNode == NULL){
            curNode =  new Node(value);
        }else if(curNode->value < value){
            curNode->right = insert(curNode->right, value);
        }else if(curNode->value > value){
            curNode->left = insert(curNode->left, value);
        }else {
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
    for(int i = 0 ; i < n; i++){
        cin >> value;
        tree.insert(value);
    }
    int dividedBy;
    cin >> dividedBy;
    tree.printSpecific(dividedBy);
    return 0;
}
