class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> op;
        int ind;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                op.push({s[i],i});
            }
            if(s[i]==')')
            {
                if(op.empty())
                {
                    s[i] = '.';
                }
                else
                {
                    op.pop();
                }
            }
        }
        while(!op.empty())
        {
            auto [ch,ind] = op.top();
            s[ind] = '.';
            op.pop();
        }
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='.')
            {
                ans += s[i];
            }
        }
        return ans;
    }
};