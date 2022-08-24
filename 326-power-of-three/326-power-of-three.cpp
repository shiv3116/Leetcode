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
        int x = log(n)/log(3)+1e-6;
        int num = (int)(pow(3,x));
        cout<<x<<" "<<num;
        return num==n;
    }
};