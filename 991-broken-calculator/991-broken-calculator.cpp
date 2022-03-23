class Solution {
public:
    int brokenCalc(int n, int target) {
        int ans = 0;
        while(n!=target)
        {
            if(target>n)
            {
                if(target & 1)
                {
                    target += 1;
                }
                else
                {
                    target /= 2;
                }
            }
            else
            {
                target += 1;
            }
            ans++;
        }
        return ans;
    }
};