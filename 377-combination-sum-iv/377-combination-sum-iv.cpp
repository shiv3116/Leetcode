class Solution {
public:
    int solve(vector<int> &nums,int target,vector<int> &dp,int sum)
    {
        if(sum>target)
        {
            return 0;
        }
        if(sum==target)
        {
            return 1;
        }
        if(dp[sum]!=-1)
        {
            return dp[sum];
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]<=target)
            {
                ans += solve(nums,target,dp,sum+nums[i]);
            }
        }
        return dp[sum] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1001,-1);
        int ans = solve(nums,target,dp,0);
        return ans;
    }
};