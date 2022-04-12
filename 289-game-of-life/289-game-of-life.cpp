class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        map<pair<int,int>,int> map;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j+1<m)
                {
                    if(board[i][j+1]==1)
                        map[{i,j}]++;
                }
                if(j-1>=0)
                {
                    if(board[i][j-1]==1)
                        map[{i,j}]++;
                }
                if(i+1<n)
                {
                    if(board[i+1][j]==1)
                        map[{i,j}]++;
                    if(j-1>=0 && board[i+1][j-1]==1)
                        map[{i,j}]++;
                    if(j+1<m && board[i+1][j+1]==1)
                        map[{i,j}]++;
                }
                if(i-1>=0)
                {
                    if(board[i-1][j]==1)
                        map[{i,j}]++;
                    if(j-1>=0 && board[i-1][j-1]==1)
                        map[{i,j}]++;
                    if(j+1<m && board[i-1][j+1]==1)
                        map[{i,j}]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==0 && map[{i,j}]==3)
                    board[i][j]=1;
                else if(board[i][j]==1 && (map[{i,j}]<2 || map[{i,j}]>3))
                    board[i][j]=0;
            }
        }
    }
};