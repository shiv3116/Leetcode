class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        int f = 0;
        while(n>1)
        {
            if(n%4!=0)
            {
                f = 1;
                break;
            }
            n /= 4;
        }
        if(f==1)
            return false;
        return true;
    }
};