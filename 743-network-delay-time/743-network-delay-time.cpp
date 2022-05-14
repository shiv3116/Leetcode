class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto t:times)
        {
            graph[t[0]].push_back({t[1],t[2]});
        }
        vector<int> res(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        res[k] = 0;
        while(!pq.empty())
        {
            int v = pq.top().second;
            pq.pop();
            
            for(auto node:graph[v])
            {
                if(res[v]+node.second<res[node.first])
                {
                    res[node.first] = res[v]+node.second;
                    pq.push({res[node.first],node.first});
                }
            }
        }
        sort(res.begin()+1,res.end());
        return res[n]==INT_MAX?-1:res[n];
    }
};