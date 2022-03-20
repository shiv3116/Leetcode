class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> t,b;
        int mt=0,mb=0;
        for(int i=0;i<tops.size();i++)
        {
            t[tops[i]]++;
            mt = max(mt,t[tops[i]]);
        }
        for(int i=0;i<bottoms.size();i++)
        {
            b[bottoms[i]]++;
            mb = max(mb,b[bottoms[i]]);
        }
        int e,ans=0;
        if(mt>mb)
        {
            for(auto x:t)
            {
                if(x.second==mt)
                {
                    e = x.first;
                    break;
                }
            }
            for(int i=0;i<tops.size();i++)
            {
                if(tops[i]!=e)
                {
                    if(bottoms[i]!=e)
                    {
                        ans = -1;
                        break;
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
        }
        else
        {
            for(auto x:b)
            {
                if(x.second==mb)
                {
                    e = x.first;
                    break;
                }
            }
            for(int i=0;i<bottoms.size();i++)
            {
                if(bottoms[i]!=e)
                {
                    if(tops[i]!=e)
                    {
                        ans = -1;
                        break;
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};