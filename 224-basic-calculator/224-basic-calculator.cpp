class Solution {
private:
    unordered_map<char, int> precedence;
    void set_precedence_rules(){
        precedence['('] = -1;
        precedence['+'] = 1;
        precedence['-'] = 1;
        precedence['*'] = 2;
        precedence['/'] = 2;
        precedence['^'] = 3;
    }
    int compute_stacks(stack<char>& operators, stack<int>& operands){
        int a = operands.top();
        operands.pop();
        int b = operands.top();
        operands.pop();
        char ch = operators.top();
        operators.pop();
        if(ch == '/' && a != 0)       return b / a;
        else if(ch == '+')  return a + b;
        else if(ch == '-')  return b - a;
        else if(ch == '*')  return a * b;
        else if(ch == '^')  return (int)pow(b, a);
        return 0;
    }
public:
    int calculate(string s) {
        stack<char> operators;
        stack<int> operands;
        int i, n = s.size();
        set_precedence_rules();
        for(i = 0 ; i < n; i++){
            if(isdigit(s[i])){
                int val = s[i] - '0';
                //move only if you see a digit
                while(i + 1 < n && isdigit(s[i + 1])){
                    val = val * 10 + (s[i + 1] -'0');
                    i++;
                }
                operands.push(val);
            }
            else if(s[i] == ' ')    continue;
            else if(s[i] == '(')    operators.push(s[i]);
            else if(s[i] == ')'){
                while(operators.top() != '(')
                    operands.push(compute_stacks(operators, operands));
                //removing '('
                operators.pop();
            }
            else{
                //s[i] is a operator
                while(!operators.empty() && precedence[s[i]] <= precedence[operators.top()])
                            operands.push(compute_stacks(operators, operands));
                // check if '-' is unary
                if (i == 0 || s[i - 1] == '(') 
                        operands.push(0);
                operators.push(s[i]);
            }
        }
        while(!operators.empty())
                operands.push(compute_stacks(operators, operands));
        return operands.top();
    }
};