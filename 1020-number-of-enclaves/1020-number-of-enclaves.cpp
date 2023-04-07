class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for(int j=0;j<grid[0].size();j++) {
            dfs(0, j, grid);
            dfs(grid.size()-1, j, grid);
        }
        for(int i=0;i<grid.size();i++) {
            dfs(i, 0, grid);
            dfs(i, grid[0].size()-1, grid);
        }
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};