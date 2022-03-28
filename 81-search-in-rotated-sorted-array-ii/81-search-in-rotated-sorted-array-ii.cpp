class Solution {
public:
    bool search(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=v.back())
            {
                v.push_back(nums[i]);
            }
        }
        int i=0,j=v.size()-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(v[mid]==target)
            {
                return true;
            }
            if(v[mid]<v[j])
            {
                if(v[mid]<target && v[j]>=target)
                {
                    i = mid+1;
                }
                else
                {
                    j = mid-1;
                }
            }
            else
            {
                if(v[mid]>target && v[i]<=target)
                {
                    j = mid-1;
                }
                else
                {
                    i = mid+1;
                }
            }
        }
        return false;
    }
};