class Solution {
public:
    int ans = INT_MIN;
    int dfs(int i,int j,map<pair<int,int>,int> &dp,int prev,int n,int m,vector<vector<int>> &matrix)
    {
        if(i<0 || i==n || j<0 || j==m || matrix[i][j] <= prev)
        {
            return 0;
        }
        
        if(dp[{i,j}]>0)
        {
            return dp[{i,j}];
        }
        
        int res = 1;
        res = max(res,1+dfs(i+1,j,dp,matrix[i][j],n,m,matrix));
        res = max(res,1+dfs(i-1,j,dp,matrix[i][j],n,m,matrix));
        res = max(res,1+dfs(i,j+1,dp,matrix[i][j],n,m,matrix));
        res = max(res,1+dfs(i,j-1,dp,matrix[i][j],n,m,matrix));
        dp[{i,j}] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<pair<int,int>,int> dp;
        // int ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               ans = max(ans,dfs(i,j,dp,-1,n,m,matrix));
            }
        }
        // for(auto x:dp)
        // {
        //     // cout<<x.second<<" ";
        // }
        return ans;
    }
};