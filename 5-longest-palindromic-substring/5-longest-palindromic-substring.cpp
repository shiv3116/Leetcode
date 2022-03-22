class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1)
            return s;
        if(s.size()==2)
        {
            if(s[0]==s[1])
                return s;
            string s1 = "";
            s1 += s[1];
            return s1;
        }
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int i1=0,j1=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
            i1 = i;
            j1 = i;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = 1;
                i1 = i;
                j1 = i+1;
            }
        }
        int c = n-2;
        int ind=2;
        while(c--)
        {
            for(int i=0;i<n-ind;i++)
            {
                if(s[i]==s[i+ind] && dp[i+1][i+ind-1]==1)
                {
                    dp[i][i+ind] = 1;
                    i1 = i;
                    j1 = i+ind;
                }
            }
            ind++;
        }
        return s.substr(i1,j1-i1+1);
    }
};