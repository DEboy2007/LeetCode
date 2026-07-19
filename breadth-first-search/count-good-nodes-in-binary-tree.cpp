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
    int goodNodes(TreeNode* root) {
        int counter = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, -10000000});
        while (!st.empty()) {
            auto [curr, currMax] = st.top(); st.pop();
            if (curr->val >= currMax) counter++;
            currMax = max(currMax, curr->val);
            if (curr->left) st.push({curr->left, currMax});
            if (curr->right) st.push({curr->right, currMax});
        }
        return counter;
        
    }
};
