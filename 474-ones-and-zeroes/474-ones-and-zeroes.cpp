class Solution {
public:
    int solve(int i,vector<string> &strs,vector<vector<vector<int>>> &dp,int m,int n)
    {
        if(i==strs.size() || m<0 || n<0)
        {
            return 0;
        }
        if(m==0 && n==0)
        {
            return 0;
        }
        if(dp[i][m][n]!=-1)
        {
            return dp[i][m][n];
        }
        int zero = count(strs[i].begin(),strs[i].end(),'0');
        int one = strs[i].size()-zero;
        if(zero<=m && one <=n)
        {
            return dp[i][m][n] = max(solve(i+1,strs,dp,m,n),1+solve(i+1,strs,dp,m-zero,n-one));
        }
        return dp[i][m][n] = solve(i+1,strs,dp,m,n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans = solve(0,strs,dp,m,n);
        return ans;
    }
};