class Solution {
public:
    vector<string> ans;
    void solve(string digits,map<int,vector<char>> &m,string tmp,int i)
    {
        if(i==digits.size())
        {
            ans.push_back(tmp);
            return;
        }
        
        int d = digits[i]-'0';
        for(char c:m[d])
        {
            tmp += c;
            solve(digits,m,tmp,i+1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        map<int,vector<char>> m;
        char c = 'a';
        for(int i=2;i<=9;i++)
        {
            if(i!=7 && i!=9)
            {
                for(int j=0;j<3;j++)
                {
                    m[i].push_back(c);
                    c++;
                }
            }
            else
            {
                for(int j=0;j<4;j++)
                {
                    m[i].push_back(c);
                    c++;
                }
            }
        }
        string tmp = "";
        solve(digits,m,tmp,0);
        return ans;
    }
};