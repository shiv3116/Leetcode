class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> presum(nums.size());
        unordered_map<int,int> m;
        presum[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            presum[i] = nums[i]+presum[i-1];
        }
        int ans = 0;
        int ind = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(presum[i]==k)
            {
                ans++;
            }
            if(m[presum[i]-k]>0)
            {
                ans += m[presum[i]-k];
            }
            m[presum[i]]++;
        }
        return ans;
    }
};