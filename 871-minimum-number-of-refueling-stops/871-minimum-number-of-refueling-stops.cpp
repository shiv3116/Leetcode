class Solution {
public:
    int minRefuelStops(int target, int sf, vector<vector<int>>& v) {
        priority_queue<int> pq;
        int ans = 0;
        int i;
        for(i=0;i<v.size();i++)
        {
            if(v[i][0]>sf)
            {
                break;
            }
            pq.push(v[i][1]);
        }
        while(sf<target && !pq.empty())
        {
            sf += pq.top();
            ans += 1;
            pq.pop();
            while(i<v.size() && v[i][0]<=sf)
            {
                pq.push(v[i][1]);
                i++;
            }
        }
        if(sf<target)
            return -1;
        return ans;
    }
};