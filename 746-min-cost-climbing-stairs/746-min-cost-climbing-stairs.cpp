class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans1 = cost[0],ans2=cost[1];
        for(int i=2;i<n;i++)
        {
            int curr = min(ans1,ans2)+cost[i];
            ans1 = ans2;
            ans2 = curr;
        }
        return min(ans1,ans2);
    }
};