class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m,m1;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            m1[s[i]]=i;
        }
        int ind = s.size();
        for(auto x:m)
        {
            if(x.second==1)
            {
                ind = min(ind,m1[x.first]);
            }
        }
        if(ind==s.size())
            ind = -1;
        return ind;
    }
};