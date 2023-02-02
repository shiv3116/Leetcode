class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i=0;i<order.size();i++) {
            mp[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++) {
            int j = 0, k = 0, f = 0;
            while(j<words[i].size() && k<words[i+1].size()) {
                if(mp[words[i][j]] > mp[words[i+1][k]]) {
                    return false;
                }
                if(mp[words[i][j]]<mp[words[i+1][k]]) {
                    f = 1;
                    break;
                }
                j++;
                k++;
            }
            if(f == 0 && words[i].size() > words[i+1].size()) {
                return false;
            }
        }
        return true;
    }
};