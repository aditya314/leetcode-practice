class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> stack_group;
    int max_freq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        stack_group[freq[val]].push(val);
    }
    
    int pop() {
        int popped_val = stack_group[max_freq].top();
        stack_group[max_freq].pop();
        if(stack_group[freq[popped_val]].size() == 0)
            max_freq--;
        freq[popped_val]--;
        return popped_val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */