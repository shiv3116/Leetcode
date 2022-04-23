class Solution {
public:
    unordered_map<string,string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = "";
        srand(time(0));
        for(int i=0;i<2;i++)
        {
            s += to_string(rand());
        }
        string st = "";
        int ind;
        for(int i=longUrl.size()-1;i>=0;i--)
        {
            if(longUrl[i]=='/')
            {
                ind = i;
                break;
            }
            st += longUrl[i];
        }
        reverse(st.begin(),st.end());
        // cout<<s<<" "<<st;
        m[s]=st;
        string ans = "";
        for(int i=0;i<ind;i++)
        {
            ans += longUrl[i];
        }
        ans += '/';
        ans += s;
        longUrl = ans;
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int idx;
        string st = "";
        for(int i=shortUrl.size()-1;i>=0;i--)
        {
            if(shortUrl[i]=='/')
            {
                idx = i;
                break;
            }
            st += shortUrl[i];
        }
        string ans = "";
        for(int i=0;i<idx;i++)
        {
            ans += shortUrl[i];
        }
        reverse(st.begin(),st.end());
        // cout<<st;
        ans += '/';
        ans += m[st];
        shortUrl = ans;
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));