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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        int c = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int tc = 0;
            vector<int> tv;
            while(c--) {
                TreeNode* tmp = q.front();
                q.pop();
                tv.push_back(tmp->val);
                if(tmp->left!=NULL) {
                    q.push(tmp->left);
                    tc++;
                }
                if(tmp->right!=NULL) {
                    q.push(tmp->right);
                    tc++;
                }
            }
            ans.push_back(tv);
            c = tc;
        }
        return ans;
    }
};