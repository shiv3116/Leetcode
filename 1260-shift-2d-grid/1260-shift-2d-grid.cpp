class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        while(k--)
        {
            vector<vector<int>> tmp(grid.size(),vector<int>(grid[0].size(),0));
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(i==grid.size()-1 && j==grid[0].size()-1)
                    {
                        tmp[0][0] = grid[i][j];
                    }
                    else if(j==grid[0].size()-1)
                    {
                        tmp[i+1][0] = grid[i][j];
                    }
                    else
                    {
                        tmp[i][j+1] = grid[i][j];
                    }
                }
            }
            grid = tmp;
        }
        return grid;
    }
};