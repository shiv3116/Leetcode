class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(arr.begin(),arr.end()-k,x)-arr.begin(), l = r-1;
        while(k--)
        {
            if(r>=arr.size() || l>=0 && x-arr[l]<=arr[r]-x)
            {
                l--;
            }
            else
            {
                r++;
            }
        }
        return vector<int>(arr.begin()+l+1,arr.begin()+r);
    }
};