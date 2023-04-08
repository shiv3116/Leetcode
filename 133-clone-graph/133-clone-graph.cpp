/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        Node* newNode = new Node(node->val, {});
        mp[node] = newNode;
        q.push(node);
        while(!q.empty()) {
            Node* tmp = q.front();
            vector<Node*> neigh = tmp->neighbors;
            q.pop();
            for(int i=0;i<neigh.size();i++) {
                if(mp.find(neigh[i])==mp.end()) {
                    mp[neigh[i]] = new Node(neigh[i]->val, {});
                    q.push(neigh[i]);
                }
                mp[tmp]->neighbors.push_back(mp[neigh[i]]);
            }
        }
        return newNode;
    }
};