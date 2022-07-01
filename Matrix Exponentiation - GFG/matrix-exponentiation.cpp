// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    long long int mod = 1000000007;
    void multiply(int a[2][2], int b[2][2])
    {
        int mul[2][2];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                mul[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    mul[i][j] = ((mul[i][j]%mod)+(((a[i][k]%mod)*(b[k][j]%mod))%mod))%mod;
            }
        }
     
        for (int i=0; i<2; i++)
            for (int j=0; j<2; j++)
                a[i][j] = (mul[i][j]%mod);  
    }

    int power(int F[2][2], int n)
    {
        int M[2][2] = {{1,1}, {1,0}};
     
        if (n==1)
            return ((F[0][0]%mod) + (F[0][1]%mod))%mod;
     
        power(F, n/2);
     
        multiply(F, F);
     
        if (n%2 != 0)
            multiply(F, M);
     
        return ((F[0][0]%mod) + (F[0][1]%mod))%mod ;
    }
    
    int FindNthTerm(long long int n) {
        // Code here
        int f[2][2] = {{1,1},{1,0}};
        
        if(n==0 || n==1)
            return 1;
            
        return power(f,n-1);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends