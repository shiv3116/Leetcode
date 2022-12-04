typedef long long int ll;
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll totalsum = 0;
        for(int i=0;i<nums.size();i++)
        {
            totalsum += nums[i];
        }
        ll currsum = 0;
        int count = 1, ind = -1;
        double minavg = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            currsum += nums[i];
            double a1 = currsum/count;
            double a2 = (count==nums.size())?0:((totalsum-currsum)/(nums.size()-count));
            double avg = abs(a1-a2);
            if(minavg>avg)
            {
                minavg = avg;
                ind = i;
            }
            count += 1;
        }
        return ind;
    }
};