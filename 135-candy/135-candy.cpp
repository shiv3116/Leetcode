class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({ratings[i],1});
        }
        for(int i=1;i<n;i++)
        {
            if(v[i].first>v[i-1].first)
            {
                v[i].second = v[i-1].second+1;
            }
        }
        for(int i=n-1;i>0;i--)
        {
            if(v[i-1].first>v[i].first)
            {
                v[i-1].second = max(v[i].second+1,v[i-1].second);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += v[i].second;
        }
        return ans;
    }
};