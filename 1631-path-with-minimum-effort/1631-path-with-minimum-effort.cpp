class Solution {
public:
    int find(int u,vector<int> &parent)
    {
        if(parent[u]==u)
            return u;
        return parent[u] = find(parent[u],parent);
    }
    
    void unionn(int u,int v, vector<int> &parent)
    {
        u = find(u,parent);
        v = find(v,parent);
        if(u==v)
            return;
        parent[u] = v;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<int> parent(n*m);
        for(int i=0;i<n*m;i++)
        {
            parent[i] = i;
        }
        vector<vector<int>> edges;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j<m-1)
                {
                    edges.push_back({abs(heights[i][j]-heights[i][j+1]),i*m+j,i*m+j+1});
                }
                if(i<n-1)
                {
                    edges.push_back({abs(heights[i][j]-heights[i+1][j]),i*m+j,(i+1)*m+j});
                }
            }
        }
        sort(edges.begin(),edges.end());
        for(auto x:edges)
        {
            unionn(x[1],x[2],parent);
            if(find(0,parent)==find(((n-1)*m+m-1),parent))
           {
               return x[0];
           }
        }
        return 0;
    }
};