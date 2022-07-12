// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int shortestUnSub(string s, string t) {
        // code here
        int m = s.size(), n = t.size(),max=1005;
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            dp[i][0] = 1;
        }
        for(int i=0;i<=n;i++)
        {
            dp[0][i] = max;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int k;
                for(k=j-1;k>=0;k--)
                {
                    if(t[k]==s[i-1])
                    {
                        break;
                    }
                }
                if(k==-1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j],dp[i-1][k]+1);
                }
            }
        }
        if(dp[m][n]>=max)
            return -1;
            
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends