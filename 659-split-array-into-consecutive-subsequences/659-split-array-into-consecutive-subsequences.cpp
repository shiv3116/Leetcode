class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> m,m1;
        for(int x:nums)
        {
            m[x]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]<=0)
            {
                continue;
            }
            else if(m1[nums[i]-1]>0)
            {
                m[nums[i]]--;
                m1[nums[i]]++;
                m1[nums[i]-1]--;
            }
            else if(m[nums[i]+1]>0 && m[nums[i]+2]>0)
            {
                // m1[nums[i]]++;
                // m1[nums[i]+1]++;
                m1[nums[i]+2]++;
                m[nums[i]]--;
                m[nums[i]+1]--;
                m[nums[i]+2]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};