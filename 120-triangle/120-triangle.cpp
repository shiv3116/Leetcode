class Solution {
public:
    int solve(vector<vector<int>> &dp,vector<vector<int>> &triangle,int i,int j)
    {
        if(i==triangle.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        return dp[i][j] = triangle[i][j] + min(solve(dp,triangle,i+1,j),solve(dp,triangle,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return solve(dp,triangle,0,0);
    }
};