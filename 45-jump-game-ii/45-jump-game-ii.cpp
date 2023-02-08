class Solution {
public:
    int jump(vector<int>& nums) {
        int ce = 0, ans = 0, cf = 0;
        for(int i=0;i<nums.size()-1;i++) {
            cf = max(cf, i+nums[i]);
            if(i==ce) {
                ans++;
                ce = cf;
            }
        }
        return ans;
    }
};