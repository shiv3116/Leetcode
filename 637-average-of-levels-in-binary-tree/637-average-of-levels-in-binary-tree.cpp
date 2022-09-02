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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int c = 1;
        vector<double> ans;
        while(!q.empty())
        {
            int count = 0,n = 0;
            double sum = 0;
            while(c--)
            {
                sum += q.front()->val;
                if(q.front()->left!=NULL)
                {
                    q.push(q.front()->left);
                    count++;
                }
                if(q.front()->right!=NULL)
                {
                    q.push(q.front()->right);
                    count++;
                }
                q.pop();
                n++;
            }
            c = count;
            ans.push_back(sum/n);
        }
        return ans;
    }
};