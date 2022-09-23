#define mod 1000000007
class Solution {
public:
    int len(int n)
    {
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            ans = ((ans * (1LL << len(i))%mod) + i)%mod;
        }
        return ans;
    }
};