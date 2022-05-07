class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int prev = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(nums[i]);
            }
            else
            {
                while(!st.empty() && nums[i]>st.top())
                {
                    if(prev>st.top())
                        return true;
                    prev = st.top();
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        return !st.empty() && prev>st.top();
    }
};