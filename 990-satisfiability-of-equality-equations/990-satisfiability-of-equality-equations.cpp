class Solution {
public:
    int find(int a,vector<int> &parent)
    {
        if(parent[a]==a)
            return a;
        return parent[a] = find(parent[a],parent);
    }
    bool equationsPossible(vector<string>& eq) {
        vector<int> parent(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i] = i;
        }
        for(int i=0;i<eq.size();i++)
        {
            if(eq[i][1]=='=')
            {
                parent[find(eq[i][0]-'a',parent)] = find(eq[i][3]-'a',parent);
            }
        }
        for(int i=0;i<eq.size();i++)
        {
            if(eq[i][1]=='!')
            {
                if(find(eq[i][0]-'a',parent)==find(eq[i][3]-'a',parent))
                {
                    return false;
                }
            }
        }
        return true;
    }
};