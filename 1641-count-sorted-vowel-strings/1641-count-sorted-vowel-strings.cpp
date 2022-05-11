class Solution {
public:        
    vector<char> tmp = {'a','e','i','o','u'};
    void solve(int n,int &ans,int i,char ch)
    {
        if(i==n)
        {
            ans++;
        }
        else
        {
            for(auto e:tmp)
            {
                if(ch<=e)
                {
                    solve(n,ans,i+1,e);
                }
            }
        }
    }
    int countVowelStrings(int n) {
        int ans = 0;
        solve(n,ans,0,' ');
        return ans;
    }
};