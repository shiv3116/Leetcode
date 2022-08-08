class Solution {
public:
    int solve(int ind,int pind,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        if(dp[ind+1][pind+1]!=-1)
        {
            return dp[ind+1][pind+1];
        }
        int len = solve(ind+1,pind,nums,dp);
        if(pind==-1 || nums[pind]<nums[ind])
        {
            len = max(len,1+solve(ind+1,ind,nums,dp));
        }
        return dp[ind+1][pind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int ans = solve(0,-1,nums,dp);
        return ans;
    }
};