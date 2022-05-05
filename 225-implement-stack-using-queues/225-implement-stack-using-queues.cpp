class MyStack {
    queue<int> q1, q2;
    int stack_top;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        stack_top = x;
    }
    
    int pop() {
        while(q1.size() > 1){
            stack_top = q1.front();
            q1.pop();
            q2.push(stack_top);
        }
        int val = q1.front();
        q1.pop();
        swap(q1,q2);
        return val;
    }
    
    int top() {
        return stack_top;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */