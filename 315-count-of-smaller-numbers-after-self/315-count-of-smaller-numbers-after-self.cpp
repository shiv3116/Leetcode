class Solution {
public:
    void merge(int l,int r,int mid,vector<int> &ans,vector<pair<int,int>> &mp)
    {
        int i = l, j = mid+1;
        vector<pair<int,int>> tmp;
        int count = 0;
        while(i<=mid && j<=r)
        {
            if(mp[i].first<=mp[j].first)
            {
                tmp.push_back(mp[i]);
                ans[mp[i].second] += count;
                i++;
            }
            else
            {
                tmp.push_back(mp[j]);
                count++;
                j++;
            }
        }
        while(i<=mid)
        {
            tmp.push_back(mp[i]);
            ans[mp[i].second] += count;
            i++;
        }
        while(j<=r)
        {
            tmp.push_back(mp[j]);
            j++;
        }
        for(int a=l;a<=r;a++)
        {
            mp[a] = tmp[a-l];
        }
    }
    void mergesort(int l,int r,vector<int> &ans,vector<pair<int,int>> &mp)
    {
        if(l>=r)
            return;
        int mid = l + (r-l)/2;
        mergesort(l,mid,ans,mp);
        mergesort(mid+1,r,ans,mp);
        merge(l,r,mid,ans,mp);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
            mp.push_back({nums[i],i});
        }
        mergesort(0,n-1,ans,mp);
        return ans;
    }
};