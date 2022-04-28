class Solution {
public:
    vector<int> parent;
    int find(int v)
    {
        if(v==parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    void unionn(int a,int b)
    {
        int x = find(a);
        int y = find(b);
        if(x!=y)
            parent[y]=x;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
        }
        for(auto x:pairs)
        {
            unionn(x[0],x[1]);
        }
        for(auto x:pairs)
        {
            swap(s[x[0]],s[x[1]]);
        }
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> m;
        for(int i=0;i<n;i++)
        {
            m[find(i)].push(s[i]);
        }
        string ans = "";
        for(int i=0;i<n;i++)
        {
            ans += m[find(i)].top();
            m[find(i)].pop();
        }
        return ans;
    }
};