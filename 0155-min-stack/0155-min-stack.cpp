class MinStack {
    stack<int> s1;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(min.empty()) min.push(val);
        else{
            if(val<min.top()) min.push(val);
            else{
                int mini = min.top();
                min.push(mini);
            }
        }

    }
    
    void pop() {
        s1.pop();
        min.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return min.top();
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