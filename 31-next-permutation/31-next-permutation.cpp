class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i;
        for(i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i]){
                //swap(nums[i],nums[i-1]);
                break;
            }
        }
        if(i>=1 && nums[i-1]<nums[i]){
            //cout<<"YES";
            int k = n-1;
            while(nums[k]<=nums[i-1])
            {
                k--;
            }
            swap(nums[k],nums[i-1]);
            sort(nums.begin()+i,nums.end());}
        else{
            sort(nums.begin(),nums.end());
        }
    }
};