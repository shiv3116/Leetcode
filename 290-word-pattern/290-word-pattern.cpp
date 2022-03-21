class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string st = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                v.push_back(st);
                st = "";
            }
            else
            {
                st += s[i];
            }
        }
        v.push_back(st);
        if(v.size()!=pattern.size())
            return false;
        unordered_map<string,char> m;
        unordered_map<char,int> m1;
        for(int i=0;i<pattern.size();i++)
        {
            if(m.find(v[i])==m.end())
            {
                if(m1.find(pattern[i])!=m1.end())
                    return false;
                m[v[i]] = pattern[i];
                m1[pattern[i]]++;
            }
            else if(m[v[i]]!=pattern[i])
            {
                return false;
            }
        }
        return true;
    }
};