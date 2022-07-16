class Solution {
public:
    int mod = 1e9+7;
    int solve(int m,int n,int mm,int x,int y,int moves,vector<vector<vector<int>>> &dp)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return 1;
        if(moves==mm)
            return 0;
        if(dp[moves][x][y]!=-1)
            return dp[moves][x][y]%mod;
        int tmp = 0;
        tmp = (tmp+solve(m,n,mm,x-1,y,moves+1,dp))%mod;
        tmp = (tmp+solve(m,n,mm,x+1,y,moves+1,dp))%mod;
        tmp = (tmp+solve(m,n,mm,x,y-1,moves+1,dp))%mod;
        tmp = (tmp+solve(m,n,mm,x,y+1,moves+1,dp))%mod;
        dp[moves][x][y] = tmp%mod;
        return dp[moves][x][y]%mod;
    }
    int findPaths(int m, int n, int mm, int x, int y) {
        vector<vector<vector<int>>> dp(mm+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        dp[mm][m][n] = solve(m,n,mm,x,y,0,dp);
        return dp[mm][m][n];
    }
};