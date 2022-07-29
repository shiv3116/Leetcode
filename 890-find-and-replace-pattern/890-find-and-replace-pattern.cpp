class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string pm = "";
        unordered_map<char,int> m;
        for(int i=0;i<pattern.size();i++)
        {
            if(m.find(pattern[i])!=m.end())
            {
                pm += (char)(m[pattern[i]]+'0');
            }
            pm += (char)(i+'0');
            m[pattern[i]] = i;
        }
        m.clear();
        for(int i=0;i<words.size();i++)
        {
            string tmp = "";
            for(int j=0;j<words[i].size();j++)
            {
                if(m.find(words[i][j])!=m.end())
                {
                    tmp += (char)(m[words[i][j]]+'0');
                }
                tmp += (char)(j+'0');
                m[words[i][j]] = j;
            }
            if(tmp==pm)
            {
                ans.push_back(words[i]);
            }
            m.clear();
        }
        return ans;
    }
};