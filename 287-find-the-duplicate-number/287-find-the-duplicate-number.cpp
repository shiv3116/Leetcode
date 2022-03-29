class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums[0],n1=0,ans;
        for(int i=1;i<nums.size();i++)
        {
            if((n^nums[i])==0)
            {
                ans = nums[i];
                break;
            }
            else
            {
                if((n^nums[i])==n1)
                {
                    ans = nums[i];
                    break;
                }
                n1 = n^nums[i];
            }
        }
        return ans;
    }
};