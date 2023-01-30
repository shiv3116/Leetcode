class Solution {
public:
    void merge(int l, int mid, int r, vector<int> &nums, int &ans) {
        int a = l, b = mid+1;
        while(a<=mid && b<=r) {
            if((long)nums[a]>(long)2*nums[b]) {
                ans += (mid-a+1);
                b++;
            }
            else {
                a++;
            }
        }
        int n1 = mid-l+1, n2 = r-mid;
        vector<int> v1(n1), v2(n2);
        int i=0, j=0, k=l;
        for(int ind=0;ind<n1;ind++) {
            v1[ind] = nums[l+ind];
        }
        for(int ind=0;ind<n2;ind++) {
            v2[ind] = nums[mid+1+ind];
        }
        while(i<n1 && j<n2) {
            if(v1[i]<=v2[j]) {
                nums[k] = v1[i];
                i++; k++;
            }
            else {
                nums[k] = v2[j];
                j++; k++;
            }
        }
        while(i<n1) {
            nums[k] = v1[i];
            i++; k++;
        }
        while(j<n2) {
            nums[k] = v2[j];
            j++; k++;
        }
    }
    void mergesort(int l, int r, vector<int> &nums, int &ans) {
        if(l<r) {
            int mid = (l+r)/2;
            mergesort(l, mid, nums, ans);
            mergesort(mid+1, r, nums, ans);
            merge(l, mid, r, nums, ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        mergesort(0, n-1, nums, ans);
        return ans;
    }
};