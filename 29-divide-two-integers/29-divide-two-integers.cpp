class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        long quo = 0, x;
        int sign;
        if(dividend<0 && divisor<0)
        {
            sign = 1;
        }
        else
        {
            sign = dividend<0?-1:divisor<0?-1:1;
        }
        long dvd = abs(dividend);
        long dvs = abs(divisor);
        while(dvd>=dvs)
        {
            long y = dvs;
            x = 1;
            while((y<<1)<=dvd)
            {
                y<<=1;
                x<<=1;
            }
            dvd -= y;
            quo += x;
        }
        if(sign*quo>INT_MAX)
            return INT_MAX;
        else if(sign*quo<INT_MIN)
            return INT_MIN;
        return sign*quo;
    }
};