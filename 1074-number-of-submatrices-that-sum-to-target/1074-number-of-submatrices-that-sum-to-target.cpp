class Solution {
public:
    int diff(vector<vector<int>>& matrix, int j, int i1, int i2) {
        if(i1 and j) 
            return matrix[i2][j] - matrix[i1-1][j] - matrix[i2][j-1] + matrix[i1-1][j-1];
        else if(i1) return matrix[i2][j] - matrix[i1-1][j];
        else if(j) return matrix[i2][j] - matrix[i2][j-1];
        return matrix[i2][j];
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i and j) 
                    matrix[i][j] = matrix[i][j] + matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
                else if(i) matrix[i][j] += matrix[i-1][j];
                else if(j) matrix[i][j] += matrix[i][j-1];
            }
        }
        int res = 0;
        for(int i1 = 0;i1<m;i1++) {
            for(int i2 = i1;i2<m;i2++) {
                unordered_map<int, int> mp;
                int sum = 0;
                for(int j=0;j<n;j++) {
                    sum += diff(matrix, j, i1, i2);
                    res += mp[sum - target];
                    mp[sum]++;
                }
                res += mp[target];
            }
        }
        return res;
    }
};