class Solution {
public:
    double myPow(double x, int n) {
        if(x>=2 && n==INT_MIN)
            return (double)(0.0);
        int p = abs(n);
        double ans = 1.0;
        while(p>0)
        {
            if(p & 1)
            {
                ans *= x;
                p -= 1;
            }
            else
            {
                x *= x;
                p /= 2;
            }
        }
        if(n<0)
            ans = (double)1.0/(double)ans;
        return ans;
    }
};