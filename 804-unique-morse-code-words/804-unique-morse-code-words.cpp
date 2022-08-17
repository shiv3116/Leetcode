class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++)
        {
            string tmp = "";
            for(int j=0;j<words[i].size();j++)
            {
                tmp += v[words[i][j]-'a'];
            }
            m[tmp]++;
        }
        return m.size();
    }
};