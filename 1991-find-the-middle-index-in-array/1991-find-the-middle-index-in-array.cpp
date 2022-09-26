class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int right = 0,left = 0,i;
        for(i=nums.size()-1;i>=0;i--)
        {
            left += nums[i];
        }
        for(i=0;i<nums.size();i++)
        {
            if(left-nums[i]==right)
                break;
            right += nums[i];
            left -= nums[i];
        }
        if(i==nums.size())
            return -1;
        return i;
    }
};