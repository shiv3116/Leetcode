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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        if(root->val==key)
        {
            if(!root->left && !root->right)
            {
                cout<<"hello";
                return NULL;
            }
            else if(root->left==NULL)
            {
                return root->right;
            }
            else if(root->right==NULL)
            {
                return root->left;
            }
            else
            {
                TreeNode *tmp = root->right;
                while(tmp->left!=NULL)
                {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode(root->right,tmp->val);
            }
        }
        if(key<root->val)
        {
            root->left = deleteNode(root->left,key);
        }
        else
        {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};