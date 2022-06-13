class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, sum = 0, ans = 0;
        unordered_map<int, int> m;
        while(j < nums.size()) {
            m[nums[j]]++;
            sum += nums[j];
            
            if(m.size() == j - i + 1) ans = max(ans, sum);
            
            while(m.size() < j - i + 1) {
                m[nums[i]]--;
                sum -= nums[i];
                if(!m[nums[i]]) m.erase(nums[i]);
                i++;
            }
            j++;
        }
        
        return ans;
    }
};