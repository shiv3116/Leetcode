class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1,m2;
        for(int i=0;i<s.size();i++)
        {
            if(m1.find(s[i])==m1.end())
            {
                if(m2.find(t[i])==m2.end())
                {
                    m1[s[i]] = t[i];
                    m2[t[i]] = s[i];
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(m1[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};