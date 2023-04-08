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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q!= NULL || q == NULL && p!= NULL) {
            return false;
        }
        if(p == NULL && q == NULL) {
            return true;
        }
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            TreeNode* t1 = q1.front();
            TreeNode* t2 = q2.front();
            q1.pop();
            q2.pop();
            if(t1->val != t2->val) {
                return false;
            }
            else if(t1->left == NULL && t2->left != NULL || t2->left== NULL && t1->left != NULL) {
                return false;
            }
            else if(t1->right == NULL && t2->right != NULL || t2->right== NULL && t1->right != NULL) {
                return false;
            }
            if(t1->left != NULL) {
                q1.push(t1->left);
            }
            if(t1->right != NULL) {
                q1.push(t1->right);
            }
            if(t2->left != NULL) {
                q2.push(t2->left);
            }
            if(t2->right != NULL) {
                q2.push(t2->right);
            }
        }
        return true;
    }
};