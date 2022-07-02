class Solution {
public:
    long long int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int height = INT_MIN, width = INT_MIN;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        height = max(height,horizontalCuts[0]);
        width = max(width,verticalCuts[0]);
        for(int i=0;i<horizontalCuts.size()-1;i++)
        {
            height = max(height,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        height = max(height,h-horizontalCuts[horizontalCuts.size()-1]);
        for(int i=0;i<verticalCuts.size()-1;i++)
        {
            width = max(width,verticalCuts[i+1]-verticalCuts[i]);
        }
        width = max(width,w-verticalCuts[verticalCuts.size()-1]);
        return ((height%mod)*(width%mod))%mod;
    }
};