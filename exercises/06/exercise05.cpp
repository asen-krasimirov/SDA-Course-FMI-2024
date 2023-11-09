/* LeetCode: https://leetcode.com/problems/range-sum-of-bst/description/ */

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        if (low <= root->val && root->val <= high) {
            return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
        }

        return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
