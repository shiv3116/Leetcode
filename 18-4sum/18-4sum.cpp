class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        map<vector<long>, int> m;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                map<long, int> mp;
                for(int k=j+1;k<nums.size();k++) {
                    long tofind = target;
                    tofind -= nums[i];
                    tofind -= nums[j];
                    tofind -= nums[k];
                    if(mp.find(tofind)!=mp.end() && m.find({nums[i], nums[j], nums[k], tofind})==m.end()) {
                        ans.push_back({nums[i], nums[j], nums[k], (int)tofind});
                        m[{nums[i], nums[j], nums[k], tofind}]++;
                    }
                    mp[nums[k]]++;
                }
            }
        }
        return ans;
    }
};