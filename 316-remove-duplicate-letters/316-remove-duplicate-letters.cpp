class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m,m1;
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        st.push(s[0]);
        m1[s[0]]++;
        m[s[0]]--;
        for(int i=1;i<s.size();i++)
        {
            m[s[i]]--;
            if(m1.find(s[i])==m1.end())
            {
                while(!st.empty() && st.top()>s[i] && m[st.top()]>0)
                {
                    m1.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                m1[s[i]]++;
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