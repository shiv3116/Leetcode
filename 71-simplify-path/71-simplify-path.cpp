class Solution {
public:
    string simplifyPath(string path) {
        string ans="",tmp;
        stringstream s(path);
        vector<string> st;
        while(getline(s,tmp,'/'))
        {
            if(tmp=="." || tmp=="")
                continue;
            else if(tmp=="..")
            {
                if(!st.empty())
                    st.pop_back();
            }
            else
            {
                st.push_back(tmp);
            }
        }
        for(auto x:st)
        {
            ans += "/"+x;
        }
        return ans==""?"/":ans;
    }
};