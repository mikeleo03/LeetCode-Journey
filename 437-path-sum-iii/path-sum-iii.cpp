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
    unordered_map<long, int> mp;
    int count = 0;

    void traverse(TreeNode* tree, int targetSum, long prefixSum) {
        if (!tree) return;
        prefixSum += tree->val;
        
        if (mp.find(prefixSum - targetSum) != mp.end()) count += mp[prefixSum - targetSum];
        mp[prefixSum]++;
        traverse(tree->left, targetSum, prefixSum);
        traverse(tree->right, targetSum, prefixSum);
        mp[prefixSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        traverse(root, targetSum, 0); 
        
        return count;
    }
};