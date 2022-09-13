class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i = 0, j = tokens.size()-1;
        int score = 0, ans = 0;
        while(i<=j)
        {
            if(score==0 && power<tokens[i])
            {
                break;
            }
            if(power>=tokens[i])
            {
                power -= tokens[i];
                score += 1;
                i++;
            }
            else
            {
                power += tokens[j];
                ans = max(ans,score);
                score -= 1;
                j--;
            }
        }
        ans = max(ans,score);
        return ans;
    }
};