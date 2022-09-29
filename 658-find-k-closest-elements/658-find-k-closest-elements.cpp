class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<arr.size();i++)
        {
            if(pq.empty())
            {
                pq.push({abs(x-arr[i]),arr[i]});
            }
            else
            {
                if(pq.size()>=k)
                {
                    if(abs(x-arr[i])<pq.top().first)
                    {
                        pq.pop();
                        pq.push({abs(x-arr[i]),arr[i]});
                    }
                }
                else
                {
                    pq.push({abs(x-arr[i]),arr[i]});
                }
            }
        }
        vector<int> ans;
        while(pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};