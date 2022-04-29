class Solution {
public:
    int find(int num,vector<int> &parent)
    {
        if(parent[num]==num)
            return num;
        return parent[num] = find(parent[num],parent);
    }
    
    void unionn(int a,int b,vector<int> &parent)
    {
        a = find(a,parent);
        b = find(b,parent);
        if(a!=b)
            parent[b] = a;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), m = graph[0].size();
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                if(find(i,parent)==find(graph[i][j],parent))
                    return false;
                unionn(graph[i][0],graph[i][j],parent);
            }
        }
        return true;
    }
};