class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        if(num.size()==0)
            return 0;
        sort(num.begin(),num.end());
        int ans = 0,c = 1;
        vector<int> nums;
        for(int i=0;i<num.size();i++)
        {
            if(nums.empty())
                nums.push_back(num[i]);
            else if(nums.back()!=num[i])
                nums.push_back(num[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            while(i+1<nums.size() && nums[i]+1==nums[i+1])
            {
                i++;
                c++;
            }
            ans = max(ans,c);
            c = 1;
        }
        ans = max(ans,c);
        return ans;
    }
};