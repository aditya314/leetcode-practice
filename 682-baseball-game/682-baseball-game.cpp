class Solution {
private:
    stack<int> st;
public:
    int calPoints(vector<string>& ops) {
        for(string op : ops){
            if(op == "+"){
                int x = st.top();   st.pop();
                int y = st.top();
                st.push(x);
                st.push(x + y);
            }
            else if(op == "D"){
                int x = st.top();
                st.push(x * 2);
            }
            else if(op == "C")
                st.pop();
            else
                st.push(stoi(op));
        }
        int total_sum = 0;
        while(!st.empty()){
            total_sum += st.top();
            st.pop();
        }
        return total_sum;
    }
};