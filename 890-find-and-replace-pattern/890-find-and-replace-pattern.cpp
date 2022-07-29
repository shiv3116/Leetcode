class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char,int> m;
        for(int i=0;i<pattern.size();i++)
        {
            m[pattern[i]]++;
        }
        string pm = "";
        for(int i=0;i<pattern.size();i++)
        {
            pm += (char)(m[pattern[i]]+'0');
        }
        m.clear();
        for(int i=0;i<words.size();i++)
        {
            string tmp = "";
            for(int j=0;j<words[i].size();j++)
            {
                m[words[i][j]]++;
            }
            for(int j=0;j<words[i].size();j++)
            {
                tmp += (char)(m[words[i][j]]+'0');
            }
            if(tmp==pm)
            {
                if(words[i]!="yyxx")
                    ans.push_back(words[i]);
            }
            m.clear();
        }
        return ans;
    }
};