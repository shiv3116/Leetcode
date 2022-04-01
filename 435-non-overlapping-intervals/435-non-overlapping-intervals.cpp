class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int l = 0, ans = 0;
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=intervals[l][0] && intervals[i][0]<intervals[l][1])
            {
                if(intervals[l][1]>intervals[i][1])
                {
                    l = i;
                }
                ans++;
            }
            else
            {
                l = i;
            }
        }
        return ans;
    }
};