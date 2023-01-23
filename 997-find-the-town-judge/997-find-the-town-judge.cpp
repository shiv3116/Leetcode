class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1) {
            return n;
        }
        vector<int> v(n+1, 0);
        map<int, int> m2;
        for(int i=0;i<trust.size();i++) {
            v[trust[i][0]]++;
            m2[trust[i][1]]++;
        }
        int ans = -1;
        for(int i=1;i<n+1;i++) {
            if(v[i]==0) {
                ans = i;
            }
        }
        for(auto x:m2) {
            if(x.second==n-1 && ans == x.first) {
                return ans;
            }
        }
        return -1;
    }
};