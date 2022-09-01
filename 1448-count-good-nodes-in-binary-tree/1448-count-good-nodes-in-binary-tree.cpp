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
    void solve(TreeNode* root,int &ans,int value)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=value)
        {
            ans++;
            value = root->val;
        }
        solve(root->left,ans,value);
        solve(root->right,ans,value);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root,ans,root->val);
        return ans;
    }
};