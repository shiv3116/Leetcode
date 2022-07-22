class Solution {
public:
    static bool solve(string s1,string s2,string s3,int n,int m,int len,int i,int j,int k,unordered_map<string,bool> &mp)
    {
        if(k==len)
        {
            if(i==n && j==m)
                return true;
            return false;
        }
        string key = to_string(i)+"*"+to_string(j)+"*"+to_string(k);
        if(mp.find(key)!=mp.end())
            return mp[key];
        if(i==n)
        {
            if(s2[j]==s3[k])
            {
                mp[key] = solve(s1,s2,s3,n,m,len,i,j+1,k+1,mp);
            }
            else
            {
                return false;
            }
        }
        if(j==n)
        {
            if(s1[i]==s3[k])
            {
                mp[key] = solve(s1,s2,s3,n,m,len,i+1,j,k+1,mp);
            }
        }
        bool c1,c2;
        if(s1[i]==s3[k])
            c1 = solve(s1,s2,s3,n,m,len,i+1,j,k+1,mp);
        if(s2[j]==s3[k])
            c2 = solve(s1,s2,s3,n,m,len,i,j+1,k+1,mp);
        return mp[key] = (c1 | c2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int len = s3.size();
        if(n+m != len)
            return false;
        unordered_map<string,bool> mp;
        return solve(s1,s2,s3,n,m,len,0,0,0,mp);
    }
};