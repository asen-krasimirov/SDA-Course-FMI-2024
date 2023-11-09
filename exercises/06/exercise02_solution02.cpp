#include <vector>

using namespace std;

/* LeetCode: https://leetcode.com/problems/binary-tree-inorder-traversal/description/ */

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
    void recursiveTraversal(TreeNode *root, vector<int> &vals) {
        if (root == nullptr) {
            return;
        }

        recursiveTraversal(root->left, vals);
        vals.push_back(root->val);
        recursiveTraversal(root->right, vals);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        recursiveTraversal(root, vals);
        return vals;
    }
};
