class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tsum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            tsum += nums[i];
        }
        
        int rem = tsum - x;
        if(rem==0)
        {
            return nums.size();
        }
        tsum = 0;
        int j = 0,ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            tsum += nums[i];
            while(tsum > rem && j<i)
            {
                tsum -= nums[j];
                j++;
            }
            
            if(tsum==rem)
            {
                ans = max(ans,i-j+1);
            }
        }
        return ans==0?-1:nums.size()-ans;
    }
};