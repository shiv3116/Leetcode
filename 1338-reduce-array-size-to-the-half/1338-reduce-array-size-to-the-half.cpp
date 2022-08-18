class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int x:arr)
        {
            m[x]++;
        }
        priority_queue<int> pq;
        for(auto x:m)
        {
            pq.push(x.second);
        }
        int n = arr.size(),ans = 0;
        while(pq.size() && n>arr.size()/2)
        {
            n -= pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};