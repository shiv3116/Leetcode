class Solution {
public:
    int dp[13][10001];
    int solve(int i,int n,int amount,int sum,vector<int> &coins)
    {
        if(sum==amount)
        {
            return 0;
        }
        if(i==n || sum>amount)
        {
            return 1e6;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        int res;
        if((long)sum+coins[i]<=INT_MAX)
            res = min(solve(i+1,n,amount,sum,coins),1+solve(i,n,amount,(int)sum+coins[i],coins));
        else
            res = min(solve(i+1,n,amount,sum,coins),1+solve(i,n,amount,INT_MAX,coins));
        return dp[i][sum]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int n = coins.size();
        int ans = solve(0,n,amount,0,coins);
        return ans==1e6?-1:ans;
    }
};