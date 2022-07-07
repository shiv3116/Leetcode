// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	bool prime[1000 + 1];
    void SieveOfEratosthenes()
    {
    
       memset(prime, true, sizeof(prime));
    
       for (int p = 2; p * p <= 1000; p++)
       {
    
          if (prime[p] == true)
          {
    
             for (int i = p * p; i <= 1000; i += p)
                prime[i] = false;
          }
       }
    }
    int primeFactors(int n)
    {
       int ans = 0;
       int temp = n;
       for (int i = 2; i <= temp / 2; i++)
       {
          while (n % i == 0)
          {
             ans++;
             n /= i;
          }
       }
       return ans;
    }
    bool brainGame(vector<int>nums) {
        // Code here.
        SieveOfEratosthenes();
       int count = 0;
       for (auto i : nums)
       {
          if (!prime[i])
          {
             count = count ^ (primeFactors(i) - 1);
          }
       }
    
       return count != 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends