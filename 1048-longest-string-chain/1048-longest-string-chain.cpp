class Solution {
public:
    static bool cmp(string &a, string &b)
    {
        return a.size()<b.size();
    }
    
    bool check(string curr,string prev)
    {
        if(curr.size()!=prev.size()+1)
        {
            return false;
        }
        
        int i=0,j=0;
        while(j<curr.size())
        {
            if(curr[j]==prev[i])
            {
                i++; j++;
            }
            else
            {
                j++;
            }
        }
        
        return i==prev.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(words.size(),1);
        int ans = 1;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[i],words[j]))
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};