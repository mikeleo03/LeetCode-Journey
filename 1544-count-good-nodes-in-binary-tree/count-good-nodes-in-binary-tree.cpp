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
    int count = 0;

    void traverse(TreeNode* tree, int maximum) {
        if (!tree) return;
        if (tree->val >= maximum) count++;
        if (!tree->left && !tree->right) return;
        maximum = max(maximum, tree->val);
        traverse(tree->left, maximum);
        traverse(tree->right, maximum);
    }

    int goodNodes(TreeNode* root) {
        traverse(root, INT_MIN);
        return count;
    }
};