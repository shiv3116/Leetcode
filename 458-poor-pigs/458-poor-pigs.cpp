class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest/minutesToDie;
        int pigs = 0;
        while(1)
        {
            int mx = (int)(pow(t+1,pigs)+0.5);
            if(mx>=buckets)
            {
                break;
            }
            pigs += 1;
        }
        return pigs;
    }
};