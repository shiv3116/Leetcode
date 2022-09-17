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
    int ans;

    int get(TreeNode* root) {
        if (!root)
            return 0;
        int l = get(root->left);
        int r = get(root->right);
        ans = max({ans, root->val + l + r, root->val, max(l, r) + root->val});
        return max(root->val, max(l, r) + root->val);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        get(root);
        return ans;
    }
};