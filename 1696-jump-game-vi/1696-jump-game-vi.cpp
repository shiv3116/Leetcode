class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        multiset<int,greater<int>> st;
        st.insert(ans[0]);
        for(int i=1;i<n;i++)
        {
            if(st.size()>k)
            {
                auto it = st.find(ans[i-k-1]);
                st.erase(it);
            }
            ans[i] = nums[i]+*st.begin();
            st.insert(ans[i]);
        }
        return ans[n-1];
    }
};