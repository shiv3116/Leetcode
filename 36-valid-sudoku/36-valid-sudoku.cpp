class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> m;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(m.find(board[i][j])!=m.end())
                        return false;
                    else
                        m[board[i][j]]++;
                }
            }
            m.clear();
        }
        m.clear();
        for(int j=0;j<9;j++)
        {
            for(int i=0;i<9;i++)
            {
                if(board[i][j]!='.')
                {
                    if(m.find(board[i][j])!=m.end())
                        return false;
                    else
                        m[board[i][j]]++;
                }
            }
            m.clear();
        }
        m.clear();
        int x = 9,i=0,j=0;
        while(x--)
        {
            for(int k=i;k<i+3;k++)
            {
                for(int l=j;l<j+3;l++)
                {
                    if(board[k][l]!='.')
                    {
                        if(m.find(board[k][l])!=m.end())
                            return false;
                        else
                            m[board[k][l]]++;
                    }
                }
            }
            m.clear();
            if(j+3<9)
            {
                j += 3;
            }
            else
            {
                if(i+3<9)
                {
                    i += 3;
                    j = 0;
                }
                else
                    break;
            }
        }
        return true;
    }
};