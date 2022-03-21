class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]] = i;
        }
        for(int i=0;i<s.size();)
        {
            int x = m[s[i]];
            int j;
            for(j=i;j<=x;j++)
            {
                if(m[s[j]]>x)
                    x = m[s[j]];
            }
            ans.push_back(x-i+1);
            i = x+1;
        }
        return ans;
    }
};