#define mod 1000000007
class Solution {
public:
    int solve(int n,map<char,int> &mp,vector<vector<int>> &dp,int j,char s)
    {
        if(j==n)
        {
            return 1;
        }
        if(dp[mp[s]][j]!=-1)
        {
            return dp[mp[s]][j]%mod;
        }
        long long res = 0;
        if(s=='a')
        {
            res += solve(n,mp,dp,j+1,'e');
        }
        if(s=='e')
        {
            res += solve(n,mp,dp,j+1,'a');
            res += solve(n,mp,dp,j+1,'i');
        }
        if(s=='i')
        {
            res += solve(n,mp,dp,j+1,'a');
            res += solve(n,mp,dp,j+1,'e');
            res += solve(n,mp,dp,j+1,'o');
            res += solve(n,mp,dp,j+1,'u');
        }
        if(s=='o')
        {
            res += solve(n,mp,dp,j+1,'i');
            res += solve(n,mp,dp,j+1,'u');
        }
        if(s=='u')
        {
            res += solve(n,mp,dp,j+1,'a');
        }
        return dp[mp[s]][j] = res%mod;
    }
    int countVowelPermutation(int n) {
        map<char,int> mp;
        mp['a']=0;
        mp['e']=1;
        mp['i']=2;
        mp['o']=3;
        mp['u']=4;
        vector<vector<int>> dp(5,vector<int>(n+1,-1));
        vector<char> v;
        v.push_back('a');
        v.push_back('e');
        v.push_back('i');
        v.push_back('o');
        v.push_back('u');
        long long ans = 0;
        for(int i=0;i<v.size();i++)
        {
            ans += solve(n,mp,dp,1,v[i]);
        }
        return ans%mod;
    }
};