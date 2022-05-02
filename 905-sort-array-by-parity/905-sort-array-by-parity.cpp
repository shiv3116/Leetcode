class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]&1)
            {
                if(!(nums[j] & 1))
                {
                    swap(nums[i],nums[j]);
                    i++;
                    j--;
                }
                else
                {
                    // swap(nums[i],nums[j-1]);
                    j--;
                }
            }
            else
            {
                if(nums[j] & 1)
                {
                    i++;
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return nums;
    }
};