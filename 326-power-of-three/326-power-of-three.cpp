class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }
        int x = log2(n)/log2(3);
        int num = (int)(pow(3,x));
        return num==n;
    }
};