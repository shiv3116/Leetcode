class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)
            return true;
        int ind = 0;
        for(int i=0;i<t.size();i++)
        {
            if(s[ind]==t[i])
            {
                ind += 1;
                if(ind==s.size())
                {
                    break;
                }
            }
        }
        if(ind==s.size())
            return true;
        return false;
    }
};