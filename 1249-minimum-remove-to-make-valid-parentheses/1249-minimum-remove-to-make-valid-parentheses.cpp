class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string string_without_invalid_closing_brackets = "";
        int open_bracket_count = 0, balance = 0;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '('){
                open_bracket_count++;
                balance++;
            }
            else if(s[i] == ')'){
                if(balance == 0)     continue;
                balance--;
            }
            string_without_invalid_closing_brackets += s[i];
        }
        
        string result = "";
        int open_brackets_to_keep = open_bracket_count - balance;
        for(int i = 0; i < string_without_invalid_closing_brackets.length(); i++){
            if(string_without_invalid_closing_brackets[i] == '('){
                open_brackets_to_keep--;
                if(open_brackets_to_keep < 0)   continue;
            }
            result += string_without_invalid_closing_brackets[i];
        }
        
        return result;
    }
};