class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size())
            return false;
        unordered_map<char,int> m;
        for(int i=0;i<t.size();i++)
        {
            m[t[i]]++;
        }
        int i;
        for(i=0;i<s.size();i++)
        {
            if(m[s[i]]<1)
                return false;
            m[s[i]]--;
        }
        return true;
    }
};