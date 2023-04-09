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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int c = 1;
        while(!q.empty()) {
            vector<int> tv(c);
            int tc = 0, i = 0;
            while(c--) {
                TreeNode* tmp = q.front();
                q.pop();
                tv[i] = tmp->val;
                i++;
                if(tmp->left != NULL) {
                    q.push(tmp->left);
                    tc++;
                }
                if(tmp->right != NULL) {
                    q.push(tmp->right);
                    tc++;
                }
            }
            c = tc;
            ans.push_back(tv);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};