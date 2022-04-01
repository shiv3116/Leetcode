class MinStack {
public:
    vector<int> stack;
    vector<int> min_ele;
    MinStack() {
        min_ele.push_back(INT_MAX);
    }
    
    void push(int val) {
        stack.push_back(val);
        if(min_ele.back()>val)
        {
            min_ele.push_back(val);
        }
        else
        {
            min_ele.push_back(min_ele.back());
        }
    }
    
    void pop() {
        stack.pop_back();
        min_ele.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_ele.back();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */