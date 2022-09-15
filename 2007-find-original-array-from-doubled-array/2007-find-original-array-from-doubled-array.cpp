class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1)
            return {};
        vector<int> ans;
        unordered_map<int,int> m;
        sort(changed.begin(),changed.end());
        for(int x:changed)
        {
            m[x]++;
        }
        for(int x:changed)
        {
            if(x==0)
            {
                if(m[x]>1)
                {
                    ans.push_back(x);
                    m[x] -= 2;
                }
            }
            else if(m[x*2]>0 && m[x]>0)
            {
                ans.push_back(x);
                m[x] -= 1;
                m[x*2] -= 1;
            }
            if(ans.size() == changed.size()/2)
                break;
        }
        if(ans.size()==changed.size()/2)
            return ans;
        return {};
    }
};