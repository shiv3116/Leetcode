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
    TreeNode* f=NULL;
    TreeNode* s=NULL;
    TreeNode *p = new TreeNode(INT_MIN);
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        inorder(root->left);
        if(f==NULL && p->val>root->val)
        {
            f = p;
        }
        if(f!=NULL && p->val>root->val)
        {
            s = root;
        }
        p = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)
            return;
        
        inorder(root);
        swap(f->val,s->val);
    }
};