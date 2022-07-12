class Solution {
public:
    bool check(vector<int>& matchsticks, int pos, vector<int>& sums, int side){
        if(pos == 0)
            return true;
        
        for(int i=0; i<4; i++){
            if(sums[i] + matchsticks[pos-1] <= side){
                sums[i] += matchsticks[pos-1];
                if(check(matchsticks, pos-1, sums, side))
                    return true;
                sums[i] -= matchsticks[pos-1];
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end());
        int n = matchsticks.size();
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += matchsticks[i];
        
        if(sum%4 != 0)
            return false;
        
        int maxlen = sum/4;
        vector<int> sums(4);
        return check(matchsticks, n, sums, maxlen);
    }
};