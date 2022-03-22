class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)
            return {};
        unordered_map<char,int> m;
        vector<string> ans;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end())
            {
                m[s[i]] = i;
            }
        }
        unordered_map<string,int> m2;
        for(auto x:m)
        {
            if(x.second+10<=s.size())
            {
                string str = s.substr(x.second,10);
                int c=1;
                unordered_map<string,int> m1;
                for(int i=x.second+1;i<s.size()-9;i++)
                {
                    string st = s.substr(i,10);
                    if(st==str)
                        c++;
                    m1[st]++;
                }
                for(auto x:m1)
                {
                    if(x.second>1 && m2.find(x.first)==m2.end())
                    {
                        ans.push_back(x.first);
                        m2[x.first]++;
                    }
                }
                if(c>1 && m2.find(str)==m2.end())
                {
                    ans.push_back(str);
                    m2[str]++;
                }
            }
        }
        return ans;
    }
};