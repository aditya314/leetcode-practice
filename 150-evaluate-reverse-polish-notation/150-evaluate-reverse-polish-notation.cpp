class Solution {
private:
    bool is_operator(string s){
        return (s.size() == 1 &&
                    (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')); 
    }
    int compute(int x, int y, char ch){
        if(ch == '+')       return x + y;
        else if(ch == '-')  return x - y;
        else if(ch == '*')  return x * y;
        else if(ch == '/')  return x / y;
        else                return INT_MAX;
    }
    int atoi(string s){
        int num = 0, n = s.size(), i = 0;
        int sign = (n > 0 && s[0] == '-') ? -1 : 1;
        if(sign < 0)    i = 1;   
        while(i < n){
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return sign * num;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token : tokens){
           if(is_operator(token)){
               int y = st.top();    st.pop();
               int x = st.top();    st.pop();
               int res = compute(x, y, token[0]);
               st.push(res);
           } 
           else
               st.push(atoi(token)); 
        }  
        return st.top();
    }
};