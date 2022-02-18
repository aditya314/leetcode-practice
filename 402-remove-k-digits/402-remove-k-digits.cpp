class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        for(char digit :  num){
            while(k > 0 && !st.empty() && st.top() > digit){
                st.pop();
                k--;
            }
            //0 in empty stack will block all numbers ahead,
            if(st.empty() && digit == '0')    continue;
            else    st.push(digit);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string new_string = "";
        while(!st.empty()){
            new_string = st.top() + new_string;
            st.pop();
        }
        return (new_string == "") ? "0" : new_string;
    }
};