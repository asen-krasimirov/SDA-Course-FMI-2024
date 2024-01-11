#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        vector<vector<int>> res;

        while (!q.empty()) {
            TreeNode *curr = q.front().first;
            int level = q.front().second;
            q.pop();

            if (curr != nullptr) {
                q.push({curr->left, level + 1});
                q.push({curr->right, level + 1});

                if (res.size() <= level) {
                    res.push_back(vector<int>());
                }

                res[level].push_back(curr->val);
            }
        }

        return res;
    }
};
