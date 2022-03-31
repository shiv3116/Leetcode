class Solution {
public:
    bool split(vector<int> &nums, int mid,int k)
    {
        int total = 0;
        int curr = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(curr+nums[i]<=mid)
            {
                curr += nums[i];
            }
            else
            {
                curr = nums[i];
                total++;
            }
        }
        return (total+1)<=k;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0,h=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            h += nums[i];
            l = max(l,nums[i]);
        }
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(split(nums,mid,m))
            {
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};