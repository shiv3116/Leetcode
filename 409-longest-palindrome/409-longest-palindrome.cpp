class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        int even=0,oddc=1,f=0;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        for(auto x:m)
        {
            if(x.second%2==0)
            {
                even += x.second;
            }
            else
            {
                f=1;
                oddc += (x.second-1);
            }
        }
        return even+(f==1?oddc:0);
    }
};