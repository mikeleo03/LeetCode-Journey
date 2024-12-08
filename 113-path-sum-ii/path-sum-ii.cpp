/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int target;
    vector<vector<int>> valid;

    void traverse(TreeNode* tree, int sum, vector<int>& res) {
        if (!tree) return;

        sum += tree->val;
        res.push_back(tree->val);
        traverse(tree->left, sum, res);
        if (!tree->left && !tree->right) {
            if (sum == target) valid.push_back(res);
        }
        traverse(tree->right, sum, res);
        res.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        vector<int> res;

        traverse(root, 0, res);
        return valid;
    }
};