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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty())
        {
            queue<TreeNode*> tmp = q;
            int sum = 0;
            while(!tmp.empty())
            {
                TreeNode* t = tmp.front();
                tmp.pop();
                q.pop();
                sum += t->val;
                if(t!=NULL && t->left!=NULL)
                {
                    q.push(t->left);
                }
                if(t!=NULL && t->right!=NULL)
                {
                    q.push(t->right);
                }
            }
            ans = sum;
        }
        return ans;
    }
};