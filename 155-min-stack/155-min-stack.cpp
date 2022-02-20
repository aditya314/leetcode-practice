class MinStack {
private:
    stack<int> st;
    stack<pair<int, int>> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min_stack.empty() || val < min_stack.top().first)
            min_stack.push({val, 1});
        else if(val == min_stack.top().first)
            min_stack.top().second++;
    }
    
    void pop() {
        if(st.top() == min_stack.top().first){
            min_stack.top().second--;
            if(min_stack.top().second == 0)
                min_stack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_stack.top().first;
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