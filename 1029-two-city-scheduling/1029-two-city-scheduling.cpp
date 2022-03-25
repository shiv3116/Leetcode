class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0;
        for(int i=0;i<costs.size();i++)
        {
            cost += costs[i][0];
            auto x = {costs[i][1]-costs[i][0],0};
            costs[i] = x;
        }
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size()/2;i++)
        {
            cost += costs[i][0];
        }
        return cost;
    }
};