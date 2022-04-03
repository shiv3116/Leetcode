class Solution {
public:
    static bool cmp(pair<char,int> &a, pair<char,int> &b)
    {
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        vector<pair<char,int>> arr;
        for(auto x:m)
        {
            arr.push_back({x.first,x.second});
        }
        sort(arr.begin(),arr.end(),cmp);
        string ans = "";
        for(auto x:arr)
        {
            while(x.second--)
            {
                ans += x.first;
            }
        }
        return ans;
    }
};