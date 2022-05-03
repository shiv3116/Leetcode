class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ind=-1,idx=-1;
        int p1 = nums[0],p2=nums[nums.size()-1];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<p1)
            {
                ind = i;
            }
            else
            {
                p1 = nums[i];
            }
        }
        for(int i = nums.size()-1;i>=0;i--)
        {
            if(p2<nums[i])
            {
                idx = i;
            }
            else
            {
                p2 = nums[i];
            }
        }
        if(ind>0)
            return ind-idx+1;
        return 0;
    }
};