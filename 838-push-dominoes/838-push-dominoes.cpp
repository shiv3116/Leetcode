class Solution {
public:
    string pushDominoes(string dom) {
        int sz = dom.size();
        int r = sz;
        int l = -sz;
        
        vector<int>vecr(sz,0);
        vector<int>vecl(sz, 0);
        for(int i=0; i< sz; i++){
            if(dom[i] == 'R'){
                r = sz;
                vecr[i] = r--;
            }
            else if(dom[i] == 'L'){
                r = sz;
            }
            else{
                if(r != sz) vecr[i] = r--;
                
            }
        }
        
        for(int i=sz-1; i>=0; i--){
            if(dom[i] == 'L'){
                l = -sz;
                vecr[i] = l++;
            }
            else if(dom[i] == 'R'){
                l = -sz;
            }
            else{   
                if(l != -sz) vecl[i] = l++;   
            }
        }
        
        string res;
        for(int i=0; i<sz;i++){
            if(vecr[i]+vecl[i] > 0){
                res +=  "R";
            }
            else if(vecr[i] + vecl[i] <0){
                res += "L";
            }
            else{
                res += ".";
            }
        }        
        return res;
    }
};