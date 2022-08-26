class Solution {
public:
    
    unordered_map<int, int> chk(int n) {
        unordered_map<int, int> M;
        while (n) {
            M[n % 10]++;
            n /= 10;
        }
        return M;
    }
    
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> Mn = chk(n);
        for (int i = 0; i < 31; i++) {
            if (chk(1 << i) == Mn)
                return true;
        }
        return false;
    }
};