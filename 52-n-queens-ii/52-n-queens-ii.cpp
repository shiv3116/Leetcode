class Solution {
public:
    bool check(int row,int col,int n,vector<vector<char>> &board)
    {
        int c = col; int r = row;
        while(c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            c--;
        }
        c = col;
        while(r<n && c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r++;
            c--;
        }
        r = row; c = col;
        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        return true;
    }
    void solve(int n,int &ans,int col,vector<vector<char>> &board)
    {
        if(col==n)
        {
            ans++;
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(check(row,col,n,board))
            {
                board[row][col] = 'Q';
                solve(n,ans,col+1,board);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        int ans = 0;
        solve(n,ans,0,board);
        return ans;
    }
};