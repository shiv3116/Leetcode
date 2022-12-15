#define notle ios_base::sync_with_stdio(false);cin.tie(NULL);
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &text1,string &text2)
    {
        if(i==-1 || j==-1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i]==text2[j])
            return dp[i][j] = 1+solve(i-1,j-1,text1,text2);
        return dp[i][j] = max(solve(i-1,j,text1,text2),solve(i,j-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        notle
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1.size()-1,text2.size()-1,text1,text2);
    }
};