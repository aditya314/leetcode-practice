class Solution {
public:
    void generate_parenthesis_through_backtracking(vector<string>& answer, string result_string, int current_index, int opening_brackets_count, int closing_brackets_count, int string_size){
        if(opening_brackets_count + closing_brackets_count == string_size){
            answer.push_back(result_string);
            return;
        }
        if(opening_brackets_count < (string_size / 2))
            generate_parenthesis_through_backtracking(answer, result_string + "(", current_index + 1, opening_brackets_count + 1, closing_brackets_count, string_size); 
        if(closing_brackets_count < opening_brackets_count)
            generate_parenthesis_through_backtracking(answer, result_string + ")", current_index + 1, opening_brackets_count, closing_brackets_count + 1, string_size);
    }
    
    vector<string> generateParenthesis(int n) {
        int string_size = 2 * n;
        vector<string> answer;
        string result_string; 
        generate_parenthesis_through_backtracking(answer, result_string, 0, 0, 0, string_size);
        return answer;
    }
};