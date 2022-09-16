class Solution {
public:
    int solve(vector<int> &nums,vector<int> &multipliers,int i,int k,vector<vector<int>> &dp)
    {
        if(k==multipliers.size())
        {
            return 0;
        }
        if(dp[i][k]!=INT_MIN)
        {
            return dp[i][k];
        }
        return dp[i][k] = max(nums[i]*multipliers[k]+solve(nums,multipliers,i+1,k+1,dp),nums[nums.size()-k-1+i]*multipliers[k]+solve(nums,multipliers,i,k+1,dp));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(multipliers.size(),vector<int>(multipliers.size(),INT_MIN));
        return solve(nums,multipliers,0,0,dp);
    }
};