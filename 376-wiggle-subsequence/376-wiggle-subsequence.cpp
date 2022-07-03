class Solution {
public:
    void solve(vector<int> &nums,int i,vector<int> &tmp,int &ans)
    {
        if(i==(int)nums.size())
        {
            // for(auto x:tmp)
            //     cout<<x<<" ";
            ans = max(ans,(int)tmp.size());
            // cout<<'\n';
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
        int cnt = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[0])
                cnt++;
        }
        if(cnt==nums.size())
            return 1;
        vector<int> vals;
        int f = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(vals.empty())
                vals.push_back(nums[i]);
            else if(vals.back()!=nums[i])
                vals.push_back(nums[i]);
        }
        if(vals.back()!=nums[nums.size()-1])
            vals.push_back(nums[nums.size()-1]);
        // for(auto x:vals)
        //     cout<<x<<" ";
        int ans = 0,len=0;
        vector<int> tmp;
        solve(vals,1,tmp,ans);
        return ans+1;
    }
};