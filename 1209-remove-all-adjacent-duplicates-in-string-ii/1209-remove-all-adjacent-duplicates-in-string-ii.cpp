class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        unordered_map<char,int> m;
        int c = 0;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                c++;
            }
            else if(s[i]==st.top())
            {
                c++;
                st.push(s[i]);
                if(c==k)
                {
                    while(c--)
                    {
                        st.pop();
                    }
                    if(!st.empty())
                    {
                        c = m[st.top()];
                    }
                }
            }
            else if(s[i]!=st.top())
            {
                m[st.top()] = c;
                c = 1;
                st.push(s[i]);
            }
        }
        string ans = "";
        while(st.size())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};