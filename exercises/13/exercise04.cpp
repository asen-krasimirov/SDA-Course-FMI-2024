#include <climits>

using namespace std;

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
    bool isValidSubtree(TreeNode* node, long long min, long long max) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= min) {
            return false;
        } else if (node->val >= max) {
            return false;
        }

        return isValidSubtree(node->left, min, node->val) && isValidSubtree(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValidSubtree(root, LONG_MIN, LONG_MAX);
    }
};
