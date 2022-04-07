class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int x:stones)
        {
            q.push(x);
        }
        while(q.size()!=1)
        {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            q.push(x-y);
        }
        return q.top();
    }
};