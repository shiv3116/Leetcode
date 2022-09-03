class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        for(int i=1;i<=9;i++)
        {
            q.push(i);
        }
        while(--n>0)
        {
            int sz = q.size();
            while(sz--)
            {
                int p = q.front();
                q.pop();
                for(int i=0;i<10;i++)
                {
                    if(abs(p%10-i)==k)
                    {
                        q.push(p*10+i);
                    }
                }
            }
        }
        vector<int> ans;
        while(q.size())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};