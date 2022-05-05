class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int x = k - nums[i];
            if(x==nums[i])
            {
                if(m[x]>1)
                {
                    ans++;
                    m[x] -= 2;
                }
            }
            else if(m[x]>0 && m[nums[i]]>0)
            {
                ans++;
                m[nums[i]]--;
                m[x]--;
            }
        }
        return ans;
    }
};