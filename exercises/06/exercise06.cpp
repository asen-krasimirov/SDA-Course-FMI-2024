#include <vector>
#include <queue>

using namespace std;

/* LeetCode: https://leetcode.com/problems/binary-tree-level-order-traversal/description/ */

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }

        vector<vector<int>> levels;
        queue<pair<TreeNode*, int>> nodes;

        nodes.push(pair<TreeNode*, int>(root, 0));

        while (!nodes.empty()) {
            TreeNode *current = nodes.front().first;

            if (current->left) {
                nodes.push(pair<TreeNode*, int>(current->left, nodes.front().second + 1));
            }

            if (current->right) {
                nodes.push(pair<TreeNode*, int>(current->right, nodes.front().second + 1));
            }

            if (levels.size() <= nodes.front().second) {
                levels.push_back(vector<int>());
            }

            levels[nodes.front().second].push_back(nodes.front().first->val);

            nodes.pop();
        }

        return levels;
    }
};
