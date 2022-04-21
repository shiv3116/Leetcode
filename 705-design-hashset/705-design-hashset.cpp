class MyHashSet {
public:
    vector<int> set;
    MyHashSet() {
        for(int i=0;i<1000001;i++)
        {
            set.push_back(-1);
        }
    }
    
    void add(int key) {
        set[key]=1;
    }
    
    void remove(int key) {
        set[key]=-1;
    }
    
    bool contains(int key) {
        if(set[key]==1)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */