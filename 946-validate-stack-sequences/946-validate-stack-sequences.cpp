class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for(int item : pushed){
            st.push(item);
            //greedily pop values from the stack if they are the next values to pop
            while(!st.empty() && j < popped.size() && st.top() == popped[j]){
                j++;    st.pop();
            }
        }
        return j == popped.size();
    }
};