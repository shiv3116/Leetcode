class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), n = s2.size();
        if(k>n) {
            return false;
        }
        unordered_map<char, int> mp, tcmp;
        for(int i=0;i<k;i++) {
            mp[s1[i]]++;
        }
        for(int i=0;i<k;i++) {
            tcmp[s2[i]]++;
        }
        if(mp == tcmp) {
            return true;
        }
        else {
            for(int i=1;i<n;i++) {
                if(i+k-1>=n) {
                    break;
                }
                tcmp[s2[i-1]]--;
                if(tcmp[s2[i-1]]==0) {
                    tcmp.erase(s2[i-1]);
                }
                tcmp[s2[i+k-1]]++;
                if(tcmp == mp) {
                    return true;
                }
            }
        }
        return false;
    }
};