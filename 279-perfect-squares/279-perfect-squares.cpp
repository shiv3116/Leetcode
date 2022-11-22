typedef long long int ll;
class Solution {
public:
    ll solve(int sum, int i, vector<int> &pf, ll dp[][10001],int n)
    {
        if(i>=pf.size() || sum>=n || pf[i]>n)
        {
            if(sum==n)
            {
                return 0;
            }
            return INT_MAX;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        ll p = 0, np = 0;
        p = 1+solve(sum+pf[i],i,pf,dp,n);
        np = solve(sum,i+1,pf,dp,n);
        return dp[i][sum] = min(p,np);
    }
    int numSquares(int n) {
        vector<int> pf(101);
        for(int i=1;i<=100;i++)
        {
            pf[i] = i*i;
        }
        ll dp[101][10001];
        memset(dp,-1,sizeof(dp));
        return solve(0,1,pf,dp,n);
    }
};