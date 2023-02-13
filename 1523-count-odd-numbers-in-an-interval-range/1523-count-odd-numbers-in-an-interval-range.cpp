class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high) {
            if(low & 1) {
                return 1;
            }
            return 0;
        }
        if((low & 1) && (high & 1)) {
            low += 1;
            high -= 1;
            return ((high-low)+1)/2 + 2;
        }
        else if((low & 1) && !(high & 1)) {
            low += 1;
            return ((high-low)+1)/2 + 1;
        }
        else if(!(low & 1) && (high & 1)) {
            high -= 1;
            return ((high-low)+1)/2 + 1;
        }
        return ((high-low)+1)/2;
    }
};