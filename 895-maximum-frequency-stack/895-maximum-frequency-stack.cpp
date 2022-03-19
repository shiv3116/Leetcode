class FreqStack {
public:
    unordered_map<int,int> m;
    unordered_map<int, stack<int>> m1;
    int maxf = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        maxf = max(maxf,m[val]);
        m1[m[val]].push(val);
    }
    
    int pop() {
        int num = m1[maxf].top();
        m1[maxf].pop();
        if(m1[m[num]--].empty())
        {
            maxf--;
        }
        return num;
    }
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */