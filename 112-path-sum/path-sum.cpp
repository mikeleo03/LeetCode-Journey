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
    bool valid = false;

    bool traverse(TreeNode* tree, int sum) {
        if (!tree) return false;

        // cout << tree->val << endl;
        sum += tree->val;
        traverse(tree->left, sum);
        traverse(tree->right, sum);
        // cout << sum << endl;
        if (!tree->left && !tree->right) {
            // cout << sum << endl;
            if (!valid && sum == target) valid = true;
        }
        return sum == target;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;

        bool status = traverse(root, 0);       
        return valid; 
    }
};