class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0,j=0;
        for(int i=0;i<pushed.size();)
        {
            if(!st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else
            {
                st.push(pushed[i]);
                i++;
            }
        }
        while(j<popped.size())
        {
            if(!st.empty() && st.top()==popped[j])
            {
                st.pop();
            }
            j++;
        }
        if(!st.empty())
            return false;
        return true;
    }
};