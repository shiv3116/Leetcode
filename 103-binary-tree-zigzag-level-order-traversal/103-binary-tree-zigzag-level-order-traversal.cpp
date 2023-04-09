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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        int c = 1, f = 0;
        q.push(root);
        while(!q.empty()) {
            int tc = 0;
            vector<int> tv;
            while(c--) {
                TreeNode* tmp = q.front();
                q.pop();
                tv.push_back(tmp->val);
                if(tmp->left != NULL) {
                    q.push(tmp->left);
                    tc++;
                }
                if(tmp->right != NULL) {
                    q.push(tmp->right);
                    tc++;
                }
            }
            if(f == 1) {
                reverse(tv.begin(), tv.end());
            }
            ans.push_back(tv);
            c = tc;
            f = (f==0)?1:0;
        }
        return ans;
    }
};