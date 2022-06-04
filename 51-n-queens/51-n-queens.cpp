class Solution {
public:
    vector<vector<string>> res;
    bool check(int row,int col,vector<vector<char>> &ans,int n)
    {
        int c = col;
        int r = row;
        while(c>=0)
        {
            if(ans[r][c]=='Q')
                return false;
            c--;
        }
        
        c = col;
        r = row;
        while(r<n && c>=0)
        {
            if(ans[r][c]=='Q')
                return false;
            r++;
            c--;
        }
        
        c = col;
        r = row;
        while(r>=0 && c>=0)
        {
            if(ans[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        return true;
    }
    void solve(int n,vector<vector<char>> &ans,int col)
    {
        if(col==n)
        {
            vector<string> tmp;
            for(auto x:ans)
            {
                string st = "";
                for(auto y:x)
                {
                    st += y;
                }
                tmp.push_back(st);
            }
            res.push_back(tmp);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(check(row,col,ans,n))
            {
                ans[row][col] = 'Q';
                solve(n,ans,col+1);
                ans[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> ans(n,vector<char>(n,'.'));
        solve(n,ans,0);
        return res;
    }
};