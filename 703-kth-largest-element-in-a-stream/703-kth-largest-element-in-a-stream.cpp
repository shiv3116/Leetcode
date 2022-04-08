class KthLargest {
public:
    vector<int> arr;
    int k, n;
    
    KthLargest(int k, vector<int>& nums) {
        arr = nums;
        sort(arr.begin(), arr.end());
        
        this->k = k;
        n = arr.size();
    }
    
    int add(int val) {
        
        auto it = arr.begin();
        
        while(it != arr.end())
        {
            if(*it >= val)
                break;
            
            it++;
        }
        
        arr.insert(it, val);
        n++;
        
        return arr[n-k];
    }
}; 
