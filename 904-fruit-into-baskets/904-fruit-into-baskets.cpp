class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int f1 = fruits[0], f2 = -1, f1c = 1, f2c = 0, ans = 0;
        for(int i=1;i<fruits.size();i++) {
            if(fruits[i] == f1) {
                f1c++;
            }
            else if(fruits[i] == f2) {
                f2c++;
            }
            else if(f2 == -1) {
                f2 = fruits[i];
                f2c++;
            }
            else {
                ans = max(ans, f1c+f2c);
                f1 = fruits[i-1];
                f1c = 0;
                int j = i-1;
                while(j>=0 && fruits[j] == f1) {
                    f1c++;
                    j--;
                }
                f2 = fruits[i];
                f2c = 1;
            }
        }
        ans = max(ans, f1c+f2c);
        return ans;
    }
};