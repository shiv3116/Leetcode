class Solution {
public:
    int maxProduct(vector<string>& word) {
        int ans = 0;
        for(int i=0;i<word.size();i++)
        {
            unordered_map<char,int> m;
            for(auto ch:word[i])
            {
                m[ch]++;
            }
            for(int j=i+1;j<word.size();j++)
            {
                int f = 0;
                for(auto x:word[j])
                {
                    if(m.find(x)!=m.end())
                    {
                        f = 1;
                        break;
                    }
                }
                if(f==0)
                    ans = max(ans,((int)word[i].size()*(int)word[j].size()));
            }
        }
        return ans;
    }
};