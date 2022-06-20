class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string,int> m;
        for(auto x:words)
        {
            m[x]++;
        }
        for(string s:words)
        {
            for(int i=1;i<s.size();i++)
            {
                m.erase(s.substr(i,s.size()));
            }
        }
        int ans = 0;
        for(auto x:m)
        {
            ans += x.first.size()+1;
        }
        return ans;
    }
};