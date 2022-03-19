class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        unordered_map<char,vector<int>> m;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==pattern[0] || text[i]==pattern[1])
            {
                m[text[i]].push_back(i);
            }
        }
        long long subs = 0;
        long long sc = 0;
        for(int i=text.size()-1;i>=0;i--)
        {
            int flag = 0;
            if(text[i]==pattern[1])
            {
                sc++;
                flag = 1;
            }
            if(text[i]==pattern[0])
            {
                subs += sc;
            }
            if(flag && pattern[0]==pattern[1])
            {
                subs--;
            }
        }
        if(m[pattern[0]].size()<m[pattern[1]].size())
        {
            subs += m[pattern[1]].size();
        }
        else
        {
            subs += m[pattern[0]].size();
        }
        return subs;
    }
};