#include <vector>
#include <stack>

using namespace std;

/* LeetCode: https://leetcode.com/problems/binary-tree-inorder-traversal/description/ */
/* solution not accepted */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void fillLeft(TreeNode *current, stack<TreeNode*> &nodes) {
        while (current) {
            fillNodes(current, nodes);
            current = current->left;
        }
    }

    void fillRight(TreeNode *current, stack<TreeNode*> &nodes) {
        while (current) {
            fillNodes(current, nodes);
            current = current->right;
        }
    }

    void fillNodes(TreeNode *current, stack<TreeNode*> &nodes) {
        fillLeft(current->right, nodes);
        nodes.push(current);
        fillRight(current->left, nodes);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        stack<TreeNode*> nodes;

        if (root == nullptr) {
            return vals;
        }

        fillNodes(root, nodes);

        while (!nodes.empty()) {
            vals.push_back(nodes.top()->val);
            nodes.pop();
        }

        return vals;
    }
};
