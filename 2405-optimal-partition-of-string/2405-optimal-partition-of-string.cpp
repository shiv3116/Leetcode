class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int ans = 1;
        for(int i = 0;i<n;i++) {
            if(mp.find(s[i])!=mp.end()) {
                ans++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return ans;
    }
};