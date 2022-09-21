class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for(int x:nums)
        {
            if(!(x & 1))
            {
                sum += x;
            }
        }
        for(auto x:queries)
        {
            if(!(nums[x[1]] & 1))
            {
                sum -= nums[x[1]];
            }
            nums[x[1]] += x[0];
            if(!(abs(nums[x[1]]) & 1))
            {
                sum += nums[x[1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};