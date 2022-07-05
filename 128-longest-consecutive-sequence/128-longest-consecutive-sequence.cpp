class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        if(num.size()==0)
            return 0;
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<num.size();i++)
        {
            pq.push(num[i]);
        }
        int ans = 0,c = 1;
        vector<int> nums;
        while(!pq.empty())
        {
            if(nums.empty())
            {
                nums.push_back(pq.top());
                pq.pop();
            }
            else if(nums.back()!=pq.top())
            {
                nums.push_back(pq.top());
                pq.pop();
            }
            else
            {
                pq.pop();
            }
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