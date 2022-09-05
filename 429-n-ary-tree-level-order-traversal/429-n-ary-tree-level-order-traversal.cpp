/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        {
            return {};
        }
        queue<Node*> q;
        q.push(root);
        int c = 1;
        vector<vector<int>> ans;
        while(q.size())
        {
            int count = 0;
            vector<int> t;
            while(c--)
            {
                Node* tmp = q.front();
                q.pop();
                t.push_back(tmp->val);
                vector<Node*> nt = tmp->children;
                count += nt.size();
                for(int i=0;i<nt.size();i++)
                {
                    q.push(nt[i]);
                }
            }
            c = count;
            ans.push_back(t);
        }
        return ans;
    }
};