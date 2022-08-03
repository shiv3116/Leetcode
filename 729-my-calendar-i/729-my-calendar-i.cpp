class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(s.empty())
        {
            s.insert({start,end});
            return true;
        }
        auto it = s.upper_bound({start,end});
        
        if(it==s.begin()){
            if(end<=(*it).first){
                s.insert({start,end});
                return true;
            }
            else{
                return false;
            }
        }
        
        if(it!=s.end()){
            if((*it).first<end){
                return false;
            }
        }
        
        it--;
        
        if(start>=(*it).second){
            s.insert({start,end});
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */