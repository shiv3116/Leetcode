class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length();
        int m = p.length();
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++)
        {
            mp[p[i]]++;
        }
        unordered_map<int,int> mp1;
        for(int i=0;i<m;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                mp1[s[i]]++;
            }
        }
        if(mp1==mp)
        {
            ans.push_back(0);
        }
        for(int i=1;i<n;i++)
        {
            if(mp.find(s[i-1])!=mp.end())
            {
                mp1[s[i-1]]--;
            }
            if(m+i-1>=n)
            {
                break;
            }
            if(mp.find(s[m+i-1])!=mp.end())
            {
                mp1[s[m+i-1]]++;
            }
            if(mp1==mp)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};