class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans;
        for(int i=0;i<n;i++)
        {
            int ind = abs(nums[i]);
            if(nums[ind]<0)
            {
                ans = ind;
                break;
            }
            nums[ind] *= -1;
        }
        return ans;
    }
};