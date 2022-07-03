class Solution {
public:
    void solve(vector<int> &nums,int i,vector<int> &tmp,int &ans)
    {
        if(i==(int)nums.size())
        {
            ans = max(ans,(int)tmp.size());
            return;
        }
        if(!tmp.empty() && tmp.back()>=0 && nums[i]-nums[i-1]>=0)
            return;
        if(!tmp.empty() && tmp.back()<0 && nums[i]-nums[i-1]<0)
            return;
        tmp.push_back(nums[i]-nums[i-1]);
        solve(nums,i+1,tmp,ans);
        tmp.pop_back();
        solve(nums,i+1,tmp,ans);
    }
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> vals;
        for(int i=0;i<nums.size();i++)
        {
            if(vals.empty())
                vals.push_back(nums[i]);
            else if(vals.back()!=nums[i])
                vals.push_back(nums[i]);
        }
        if(vals.back()!=nums[nums.size()-1])
            vals.push_back(nums[nums.size()-1]);
        int ans = 0,len=0;
        vector<int> tmp;
        solve(vals,1,tmp,ans);
        return ans+1;
    }
};