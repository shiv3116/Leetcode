#define mod 1000000007
typedef long long int ll;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<ll,ll>> a;
        for(int i=0;i<n;i++)
        {
            a.push_back({efficiency[i],speed[i]});
        }
        sort(a.begin(),a.end());
        ll ans = 0, curr = 0, mini;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=n-1;i>=n-k;i--)
        {
            curr += a[i].second;
            mini = a[i].first;
            ans = max(ans,curr*mini);
            pq.push(a[i].second);
        }
        for(int i=n-k-1;i>=0;i--)
        {
            if(pq.top()<a[i].second)
            {
                curr -= pq.top();
                curr += a[i].second;
                mini = a[i].first;
                ans = max(ans,curr*mini);
                pq.pop();
                pq.push(a[i].second);
            }
        }
        return int(ans%mod);
    }
};