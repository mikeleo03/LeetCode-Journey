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
    void traverse(TreeNode* tree, int& maximum, int& count) {
        if (!tree) return;
        // cout << "val " << tree->val << endl;
        if (maximum <= tree->val) {
            maximum = tree->val;
            // cout << "max " << maximum << endl;
            count++;
        }

        int maximum2 = maximum;
        traverse(tree->left, maximum, count);
        maximum = maximum2;
        // cout << "reset " << maximum << endl;
        traverse(tree->right, maximum, count);
    }

    int goodNodes(TreeNode* root) {
        int maximum = root->val;
        int count = 0;

        traverse(root, maximum, count);
        return count;
    }
};