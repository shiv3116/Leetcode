/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q;
        q.push(cloned);
        TreeNode* tmp;
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            // cout<<tmp->val;
            if(tmp->val==target->val)
                break;
            
            if(tmp->left!=NULL)
                q.push(tmp->left);
            if(tmp->right!=NULL)
                q.push(tmp->right);
        }
        return tmp;
    }
};