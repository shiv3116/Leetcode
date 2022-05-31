class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total = (int)pow(2,k);
        unordered_map<string,int> m;
        if(k>s.size())
            return false;
        for(int i=0;i<(s.size()-k+1);i++)
        {
            // cout<<s.substr(i,k)<<" ";
            m[s.substr(i,k)]++;
        }
        if(m.size()==total)
            return true;
        
        return false;
    }
};