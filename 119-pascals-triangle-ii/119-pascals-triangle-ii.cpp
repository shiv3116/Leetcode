class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for(int j=0;j<pascal.back().size()-1;j++)
            {
                tmp.push_back(pascal.back()[j]+pascal.back()[j+1]);
            }
            tmp.push_back(1);
            pascal.push_back(tmp);
        }
        return pascal[rowIndex];
    }
};