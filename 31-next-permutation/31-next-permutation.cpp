class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i;
        for(i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i]) // finding the breakpoint
            {
                break;
            }
        }
        if(i>=1 && nums[i-1]<nums[i]) //To check whether a breakpoint exist or not
        {
            //If breakpoint exist
            int k = n-1;
            while(nums[k]<=nums[i-1]) // Finding the number just greater than the breakpoint
            {
                k--;
            }
            swap(nums[k],nums[i-1]); //swapping it
            reverse(nums.begin()+i,nums.end());//sorting it to get the smallest permutation(reverse can also be used)
        }
        else
        {
            reverse(nums.begin(),nums.end()); // If no breakpoint exist
        }
    }
};