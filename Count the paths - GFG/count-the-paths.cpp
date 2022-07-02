// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void dfs(vector<vector<int>> &adjacent,int &count,int source,int destination)
    {
        if(source==destination)
        {
            count++;
            return;
        }
        for(auto newsource:adjacent[source])
        {
            dfs(adjacent,count,newsource,destination);
        }
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<vector<int>> adj(n);
	    for(auto x:edges)
	    {
	        adj[x[0]].push_back(x[1]);
	    }
	    int ans = 0;
	    dfs(adj,ans,s,d);
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends