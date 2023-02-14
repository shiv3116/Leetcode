class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int min = n1<n2?n1:n2;
        char c = '0';
        string s = "";
        n1 = n1-1;
        n2 = n2-1;
        for(int i=0;i<min;i++)
        {
            if(n1==0 && n2==0)
            {
                n1=-1;n2=-1;
                break;
            }
            if(a[n1]=='1' && b[n2]=='1' && c=='0')
            {
                s += '0';
                c = '1';
            }
            else if(a[n1]=='1' && b[n2]=='1' && c=='1')
            {
                s += '1';
                c = '1';
            }
            else if(a[n1]=='0' && b[n2]=='1' && c=='0' || a[n1]=='1' && b[n2]=='0' && c=='0')
            {
                s += '1';
                c = '0';
            }
            else if(a[n1]=='0' && b[n2]=='1' && c=='1' || a[n1]=='1' && b[n2]=='0' && c=='1')
            {
                s += '0';
                c = '1';
            }
            else if(a[n1]=='0'&&b[n2]=='0'&&c=='1')
            {
                s += '1';
                c = '0';
            }
            else{
                s += '0';
            }
            n1--; n2--;
        }
        //cout<<n2<<" "<<c;
        for(int i=n1;i>=0;i--)
        {
            if(i==0)
            {
                if(a[i]=='1' && c=='1')
                    s += "01";
                else if(a[i]=='0'&&c=='1' || a[i]=='1'&&c=='0')
                    s += '1';
                else
                    s += '0';
            }
            else{
                if(a[i]=='1'&&c=='1')
                {
                    s += '0';
                    c = '1';
                }
                else if(a[i]=='0'&&c=='1' || a[i]=='1'&&c=='0')
                {
                    s += '1';
                    c = '0';
                }
                else{
                    s += '0';
                    c = '0';
                }
            }
        }
        for(int i=n2;i>=0;i--)
        {
            if(i==0)
            {
                if(b[i]=='1' && c=='1')
                    s += "01";
                else if(b[i]=='0'&&c=='1' || b[i]=='1'&&c=='0')
                    s += '1';
                else
                    s += '0';
            }
            else{
                if(b[i]=='1'&&c=='1')
                {
                    s += '0';
                    c = '1';
                }
                else if(b[i]=='0'&&c=='1' || b[i]=='1'&&c=='0')
                {
                    s += '1';
                    c = '0';
                }
                else{
                    s += '0';
                    c = '0';
                }
            }
        }
        if(n1==n2)
        {
            if(a[0]=='1'&&b[0]=='1'&&c=='1')
                s += "11";
            else if(a[0]=='1'&&b[0]=='1'&&c=='0' || a[0]=='0'&&b[0]=='1'&&c=='1' || a[0]=='1'&&b[0]=='0'&&c=='1')
                s += "01";
            else if(a[0]=='0'&&b[0]=='1'&&c=='0' || a[0]=='1'&&b[0]=='0'&&c=='0')
                s += '1';
            else
                s += '0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
};