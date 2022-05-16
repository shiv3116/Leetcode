class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty())
        {
            int m = q.size();
            ans++;
            for(int a=0;a<m;a++)
            {
                auto [i,j] = q.front();
                if(i==n-1 && j==n-1)
                    return ans;
                q.pop();
                for(int k=i-1;k<=i+1;k++)
                {
                    for(int l=j-1;l<=j+1;l++)
                    {
                        if((k>=0 && k<n) && (l>=0 && l<n) && (grid[k][l]==0))
                        {
                            q.push({k,l});
                            grid[k][l] = 1;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};