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
    int diameterOfBinaryTree(TreeNode* root) {
        int total = 0;
        helper(root, total);
        return total;
    }

    int helper(const TreeNode* root, int &total) {
        if (!root) return 0;
        int hl = helper(root->left, total);
        int hr = helper(root->right, total);
        total = max(total, hl + hr);
        return 1 + max(hl, hr);
    }
};