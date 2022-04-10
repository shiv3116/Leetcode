class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string x:ops)
        {
            if(x=="C")
                st.pop();
            else if(x=="D")
                st.push(st.top()*2);
            else if(x=="+")
            {
                int y = st.top();
                st.pop();
                int z = y+st.top();
                st.push(y);
                st.push(z);
            }
            else
            {
                st.push(stoi(x));
            }
        }
        int ans = 0;
        while(st.size())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};