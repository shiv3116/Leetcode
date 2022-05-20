class Solution {
public:
    int ans = 0;
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i<0 || j<0 || grid[i][j]==1)
        {
            return 0;
        }
        if(i==0 && j==0)
        {
            return 1;
        }
        if(dp[i][j]>0)
        {
            return dp[i][j];
        }
        int res = 0;
        res += solve(i-1,j,grid,dp);
        res += solve(i,j-1,grid,dp);
        return dp[i][j] += res;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return 0;
        if(n==1)
            return 1;
        vector<vector<int>> dp(n,vector<int>(m));
        solve(n-1,m-1,grid,dp);
        return dp[n-1][m-1];
    }
};