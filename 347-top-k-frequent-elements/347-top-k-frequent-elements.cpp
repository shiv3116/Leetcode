class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int,int>> arr;
        for(auto x:m)
        {
            arr.push_back({x.first,x.second});
        }
        sort(arr.begin(),arr.end(),cmp);
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};