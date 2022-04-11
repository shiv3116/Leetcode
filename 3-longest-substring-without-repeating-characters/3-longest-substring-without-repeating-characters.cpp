class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0,i=0,j=0;
        unordered_map<char,int> m;
        for(i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                // cout<<i<<" "<<j;
                if(j>m[s[i]])
                {
                    m[s[i]] = i;
                    continue;
                }
                ans = max(ans,i-j);
                j = m[s[i]]+1;
                m[s[i]] = i;
            }
            else
            {
                m[s[i]] = i;
            }
        }
        ans = max(ans,i-j);
        return ans;
    }
};