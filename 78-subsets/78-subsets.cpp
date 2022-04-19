class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &tmp, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        solve(nums,ans,tmp,i+1);
        tmp.pop_back();
        solve(nums,ans,tmp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(nums,ans,tmp,0);
        return ans;
    }
};