class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int,int>> st;
        vector<int> ans(arr.size(), 0);
        for(int i=0;i<arr.size();i++) {
            if(st.empty() || arr[i]<=st.top().first) {
                st.push({arr[i], i});
            }
            else {
                while(!st.empty() && st.top().first<arr[i]) {
                    ans[st.top().second] = i-st.top().second;
                    st.pop();
                }
                st.push({arr[i],i});
            }
        }
        return ans;
    }
};