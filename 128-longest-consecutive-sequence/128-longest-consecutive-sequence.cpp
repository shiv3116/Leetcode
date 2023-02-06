class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        if(num.size()==0)
            return 0;
        set<int> pq;
        for(int i=0;i<num.size();i++)
        {
            pq.insert(num[i]);
        }
        int ans = 0,c = 1;
        vector<int> nums;
        for(int x:pq)
        {
            nums.push_back(x);
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