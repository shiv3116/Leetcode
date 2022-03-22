class Solution {
public:
    string getSmallestString(int n, int k) {
        if(k==n)
        {
            string ans = "";
            while(n--)
            {
                ans += 'a';
            }
            return ans;
        }
        string ans = "";
        int sz = 0;
        unordered_map<int,char> m;
        char ch = 'a';
        for(int i=1;i<=26;i++)
        {
            m[ch] = i;
            ch++;
        }
        ch = 'z';
        while(sz!=n)
        {
            if(k-m[ch]<n-(sz+1))
            {
                while(k-m[ch]<n-(sz+1))
                {
                    ch--;
                }
                k -= m[ch];
                ans += ch;
            }
            else
            {
                ans += ch;
                k -= m[ch];
            }
            sz++;
            if(n-sz==k)
            {
                break;
            }
        }
        while(sz!=n)
        {
            ans += 'a';
            sz++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};