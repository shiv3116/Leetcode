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
    
    int get(TreeNode* root, map<int, int>& M) {
        if (!root)
            return 0;
        M[root->val]++;
        if (!root->left && !root->right) {
            int o = 0;
            for (auto &[i, j] : M) {
                o += j & 1;
            }
            M[root->val]--;
            return o <= 1;
        }
        int x = get(root->left, M) + get(root->right, M);
        M[root->val]--;
        return x;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int, int> M;
        return get(root, M);
    }
};