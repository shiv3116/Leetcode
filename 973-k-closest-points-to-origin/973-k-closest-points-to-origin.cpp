typedef long long int ll;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<ll,int>> tmp;
        for(int i=0;i<points.size();i++)
        {
            tmp.push_back({(points[i][0]*points[i][0])+(points[i][1]*points[i][1]),i});
        }
        sort(tmp.begin(),tmp.end());
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(points[tmp[i].second]);
        }
        return ans;
    }
};