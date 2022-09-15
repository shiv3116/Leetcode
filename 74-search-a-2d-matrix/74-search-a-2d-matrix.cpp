class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int i;
        for(i=0;i<m;i++)
        {
            if(mat[i][n-1]<target)
            {
                continue;
            }
            else if(mat[i][n-1]==target)
            {
                return true;
            }
            else
            {
                break;
            }
        }
        if(i==m)
            return false;
        for(int j=n-1;j>=0;j--)
        {
            if(mat[i][j]==target)
            {
                return true;
            }
        }
        return false;
    }
};