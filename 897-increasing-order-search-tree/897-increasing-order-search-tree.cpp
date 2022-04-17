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
    TreeNode* ans = NULL;
    TreeNode* tmp;
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return;
        solve(root->left);
        if(ans==NULL)
        {
            TreeNode *t = new TreeNode(root->val);
            ans = t;
            tmp = ans;
        }
        else
        {
            TreeNode *t = new TreeNode(root->val);
            tmp->right = t;
            tmp = tmp->right;
        }
        solve(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        tmp->right = NULL;
        return ans;
    }
};