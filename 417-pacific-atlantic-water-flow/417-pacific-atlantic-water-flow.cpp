class Solution {
private:
    vector<int> a = {1,0,-1,0};
    vector<int> b = {0,1,0,-1};
    
    int vis[205][205];
    
    static bool chk(int i, int j, int dx, int dy, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if(dx<0 || dx>=n || dy<0 || dy>=m) return 0;
        if(mat[i][j] <= mat[dx][dy]) return 1;
        else return 0;
    }

    void dfs(vector<vector<int>>& mat, vector<vector<int>>& atl, int i, int j) {
        int n = mat.size(), m = mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m) return;
        
        vis[i][j] = 1;
        atl[i][j] = 1;
        
        for(int k=0; k<4; ++k) {
            int dx = i + a[k], dy = j + b[k];
            if(chk(i,j,dx,dy, mat)) {
                if(!vis[dx][dy]) dfs(mat, atl, dx, dy);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> atl(n, vector<int>(m,0));
        vector<vector<int>> pac(n, vector<int>(m,0));        
        
        vector<vector<int>> ans;
        
        memset(vis, 0, sizeof(vis));
        
        
        for(int i=0; i<n; ++i) {
            if(!vis[i][0]) dfs(mat, atl, i, 0);
        }        
        for(int j=0; j<m; ++j) {
            if(!vis[0][j]) dfs(mat, atl, 0, j);
        }
        
        memset(vis, 0, sizeof(vis));
        
        for(int i=0; i<n; ++i) {
            if(!vis[i][m-1]) dfs(mat, pac, i, m-1);
        }        
        for(int j=0; j<m; ++j) {
            if(!vis[n-1][j]) dfs(mat, pac, n-1, j);
        }
        
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(atl[i][j] + pac[i][j] == 2) ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};
