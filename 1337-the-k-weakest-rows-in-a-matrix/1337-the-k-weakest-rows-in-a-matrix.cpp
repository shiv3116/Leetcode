class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> m;
        vector<int> ans;
        for(int i=0;i<mat.size();i++)
        {
            int s = 0;
            for(int j=0;j<mat[0].size();j++)
            {
                s += mat[i][j];
            }
            m.push_back({s,i});
        }
        sort(m.begin(),m.end(),cmp);
        for(int i=0;i<k;i++)
        {
            ans.push_back(m[i].second);
        }
        return ans;
    }
};