class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int key = 1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ans[i] = key;
            key *= nums[i];
        }
        key = 1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i] *= key;
            key *= nums[i];
        }
        return ans;
    }
};