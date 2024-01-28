#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unordered_map<TreeNode *, TreeNode *> parents;
    unordered_set<TreeNode *> pParents;

    void dfs(TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            parents[node->left] = node;
        }

        if (node->right != nullptr) {
            parents[node->right] = node;
        }

        dfs(node->left);
        dfs(node->right);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);

        TreeNode *temp = p;

        while (temp != root) {
            pParents.insert(temp);
            temp = parents[temp];
        }

        pParents.insert(root);

        temp = q;

        while (true) {
            if (pParents.find(temp) != pParents.end()) {
                return temp;
            }

            temp = parents[temp];
        }

//        return root;
    }
};
