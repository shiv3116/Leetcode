class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i1 = num1.size() - 1, i2 = num2.size() - 1, carry = 0;
        while (i1 >= 0 || i2 >= 0 || carry > 0) {
            if (i1 >= 0) {
                carry += num1[i1] - '0';
                i1 -= 1;
            }
            if (i2 >= 0) {
                carry += num2[i2] - '0';
                i2 -= 1;
            }
            ans += char(carry % 10 + '0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<string> temp;
        string ans = "";
        for(int i=num2.size()-1;i>=0;i--)
        {
            string tmp = "";
            int a = num2[i]-'0';
            char carry = '0';
            for(int j=num1.size()-1;j>=0;j--)
            {
                int b = num1[j]-'0';
                if(carry=='0')
                {
                    if(a*b>9)
                    {
                        string t = to_string(a*b);
                        tmp += t[1];
                        carry = t[0];
                    }
                    else
                    {
                        string t = to_string(a*b);
                        tmp += t[0];
                    }
                }
                else
                {
                    if(a*b>9)
                    {
                        string t = to_string((a*b)+(carry-'0'));
                        tmp += t[1];
                        carry = t[0];
                    }
                    else
                    {
                        string t = to_string((a*b)+(carry-'0'));
                        if(t.size()>1)
                        {
                            tmp += t[1];
                            carry = t[0];
                        }
                        else
                        {
                            tmp += t[0];
                            carry = '0';
                        }
                    }
                }
            }
            if(carry!='0')
                tmp += carry;
            reverse(tmp.begin(),tmp.end());
            temp.push_back(tmp);
        }
        int ind = 0;
        for(auto x:temp)
        {
            for(int i=0;i<ind;i++)
            {
                x += '0';
            }
            temp[ind] = x;
            ind++;
        }
        ans = temp[0];
        for(int i=1;i<temp.size();i++)
        {
            ans = addStrings(ans,temp[i]);
        }
        int c = 0;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='0')
                c++;
        }
        if(c==ans.size())
            ans = "0";
        return ans;
    }
};