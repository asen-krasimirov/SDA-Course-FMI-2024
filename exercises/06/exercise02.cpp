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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>();
        }

        vector<int> vals;

        for (int val : inorderTraversal(root->left)) {
            vals.push_back(val);
        }

        vals.push_back(root->val);

        for (int val : inorderTraversal(root->right)) {
            vals.push_back(val);
        }

        return vals;
    }
};
