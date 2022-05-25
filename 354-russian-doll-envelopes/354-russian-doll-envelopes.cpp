class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> tmp;
        tmp.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++)
        {
            if(envelopes[i][1]>tmp.back())
            {
                tmp.push_back(envelopes[i][1]);
            }
            else
            {
                auto ind = lower_bound(tmp.begin(),tmp.end(),envelopes[i][1]);
                tmp[ind-tmp.begin()] = envelopes[i][1];
            }
        }
        return tmp.size();
    }
};