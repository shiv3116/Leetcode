class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string ans = "";
        int i = n1-1, j = n2-1;
        char carry = '0';
        while(i>=0 && j>=0)
        {
            int a = num1[i]-'0';
            int b = num2[j]-'0';
            if(carry=='0')
            {
                string s;
                if(a+b>9)
                {
                    s = to_string(a+b);
                    ans += s[1];
                    carry = s[0];
                }
                else
                {
                    s = to_string(a+b);
                    ans += s[0];
                }
            }
            else
            {
                string s;
                if(a+b+(carry-'0')>9)
                {
                    s = to_string(a+b+(carry-'0'));
                    ans += s[1];
                    carry = s[0];
                }
                else
                {
                    s = to_string(a+b+(carry-'0'));
                    ans += s[0];
                    carry = '0';
                }
            }
            i--; j--;
        }
        while(i>=0)
        {
            if(carry!='0')
            {
                string s = to_string((num1[i]-'0')+(carry-'0'));
                if(s.size()>1)
                {
                    ans += s[1];
                    carry = s[0];
                }
                else
                {
                    ans += s[0];
                    carry = '0';
                }
            }
            else
            {
                ans += num1[i];
            }
            i--;
        }
        while(j>=0)
        {
            if(carry!='0')
            {
                string s = to_string((num2[j]-'0')+(carry-'0'));
                if(s.size()>1)
                {
                    ans += s[1];
                    carry = s[0];
                }
                else
                {
                    ans += s[0];
                    carry = '0';
                }
            }
            else
            {
                ans += num2[j];
            }
            j--;
        }
        if(carry!='0')
        {
            ans += carry;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};