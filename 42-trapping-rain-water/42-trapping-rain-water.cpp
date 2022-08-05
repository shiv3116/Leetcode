class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        vector<int> pm;
        vector<int> sm;
        pm.push_back(v[0]);
        sm.push_back(v[n-1]);
        for(int i=1;i<n;i++)
        {
            pm.push_back(max(v[i],pm.back()));
        }
        for(int i=n-2;i>=0;i--)
        {
            sm.push_back(max(v[i],sm.back()));
        }
        reverse(sm.begin(),sm.end());
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            int h = min(pm[i-1],sm[i+1]);
            if(h>=v[i])
            {
                ans += h-v[i];
            }
        }
        return ans;
    }
};