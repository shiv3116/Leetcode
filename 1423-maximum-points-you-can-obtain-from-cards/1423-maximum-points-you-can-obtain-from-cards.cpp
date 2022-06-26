class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        vector<int> presum(arr.size());
        presum[0] = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            presum[i] = presum[i-1]+arr[i];
        }
        if(k==arr.size())
        {
            return presum[arr.size()-1];
        }
        k = arr.size()-k;
        int max_sum = INT_MIN;
        for(int i=0;i<arr.size()-k+1;i++)
        {
            if(i!=0)
                max_sum = max(max_sum,presum[arr.size()-1]-(presum[i+k-1]-presum[i-1]));
            else
                max_sum = max(max_sum,presum[arr.size()-1]-presum[i+k-1]);
        }
        return max_sum;
    }
};