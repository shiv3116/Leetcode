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
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        q.push(root);
        ans.push_back({root->val});
        queue<TreeNode*> q1;
        vector<int> v;
        while(1)
        {
            queue<TreeNode*> q1;
            vector<int> v;
            while(!q.empty())
            {
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left!=NULL)
                {
                    q1.push(tmp->left);
                    v.push_back(tmp->left->val);
                }
                if(tmp->right!=NULL)
                {
                    q1.push(tmp->right);
                    v.push_back(tmp->right->val);
                }
            }
            if(q1.empty())
                break;
            q = q1;
            ans.push_back(v);
        }
        return ans;
    }
};