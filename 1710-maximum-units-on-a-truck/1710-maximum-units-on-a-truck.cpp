class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        sort(box.begin(),box.end(),cmp);
        int ans = 0;
        for(auto x:box)
        {
            if(truckSize>=x[0])
                ans += (x[0]*x[1]);
            else
                ans += (truckSize*x[1]);
            
            truckSize -= x[0];
            
            if(truckSize<=0)
                break;
        }
        return ans;
    }
};