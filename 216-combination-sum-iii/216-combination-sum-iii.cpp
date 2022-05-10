class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> &tmp,int k,int n,int i,int j,int sum)
    {
        if(j==nums.size())
        {
            if(sum==n && i==k)
            {
                ans.push_back(tmp);
            }
            return;
        }
        if(i==k)
        {
            // cout<<sum<<'\n';
            if(sum==n)
            {
                ans.push_back(tmp);
            }
            return;
        }
        tmp.push_back(nums[j]);
        sum += nums[j];
        solve(nums,tmp,k,n,i+1,j+1,sum);
        sum -= tmp.back();
        tmp.pop_back();
        solve(nums,tmp,k,n,i,j+1,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> tmp;
        solve(nums,tmp,k,n,0,0,0);
        return ans;
    }
};