class Solution {
public:
    string convert(string s, int n) {
        string arr[n][1001];
        int i = 0, j = 0, f = 0;
        for(int k = 0;k < s.size();k++) {
            if(f==0) {
                arr[i][j] = s[k];
                i++;
                if(i==n) {
                    f = 1;
                    if(i-2>=0)
                        i -= 2;
                    else
                        i = 0;
                    j++;
                }
            }
            else {
                arr[i][j] = s[k];
                i--;
                j++;
                if(n!=2 && i<=0) {
                    f = 0;
                    i = 0;
                }
                else if(n==2) {
                    if(i==0) {
                        f = 0;
                    }
                    else {
                        f = 0;
                        i = 1;
                    }
                }
            }
        }
        string ans = "";
        for(i=0;i<n;i++) {
            for(j=0;j<1001;j++) {
                ans += arr[i][j];
            }
        }
        return ans;
    }
};