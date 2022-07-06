class Solution {
public:
    int fib(int n) {
        int a=0,b=1;
        if(n==0)
        {
            return a;
        }
        else if(n==1)
        {
            return b;
        }
        else
        {
            n = n-1;
            int c;
            while(n--)
            {
                c = a+b;
                a = b;
                b = c;
            }
            return c;
        }
    }
};