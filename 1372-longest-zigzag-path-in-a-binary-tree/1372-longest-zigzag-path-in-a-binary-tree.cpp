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
    void solve(TreeNode* root, int dir, int &ans, int count) {
        if(root==NULL) {
            return;
        }
        ans = max(ans, count);
        if(dir==1) {
            solve(root->right, -1, ans, count+1);
            solve(root->left, 1, ans, 1);
        }
        else {
            solve(root->left, 1, ans, count+1);
            solve(root->right, -1, ans, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, 1, ans, 0);
        solve(root, -1, ans, 0);
        return ans;
    }
};