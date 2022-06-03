class NumMatrix {
public:
    int r,c;
    vector<vector<int>> s;
    NumMatrix(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        s = vector<vector<int>>(r, vector<int>(c, 0));
        for(int i=0;i<r;i++)
        {
            s[i][0] = matrix[i][0];
        }
        for(int i=0;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                s[i][j] = s[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int su = 0;
        for(int i=row1;i<=row2;i++)
        {
            if(col1>=1){
                su += s[i][col2]-s[i][col1-1];
            }
            else
            {
                su += s[i][col2];
            }
        }
        return su;
    }
};