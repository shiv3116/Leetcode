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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        TreeNode *tmp = root;
        queue<TreeNode*> q;
        q.push(tmp);
        vector<vector<int>> res;
        while(!q.empty())
        {
            queue<TreeNode*> q1 = q;
            vector<int> tmp1;
            while(!q1.empty())
            {
                TreeNode *t = q1.front();
                tmp1.push_back(t->val);
                q.pop();
                q1.pop();
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
            }
            res.push_back(tmp1);
        }
        vector<int> ans;
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i][res[i].size()-1]);
        }
        return ans;
    }
};