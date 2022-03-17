class Solution {
public:
    int scoreOfParentheses(string s) {
        int size = 0,flag = 1;
        int res = 0;
        for(int i=0; i<s.size();i++)
        {
            if(s[i]== '(')
            {
                size++;
                flag = 1;
            }
            else
            {
                res += pow(2, size-1)*flag; 
                size--;
                flag = 0;
            }
        }
        return res;
    }
};