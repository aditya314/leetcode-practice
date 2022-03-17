class Solution {
public:
    int scoreOfParentheses(string S) {
        int score = 0, depth = 0;
        for (int i = 0; i < S.length(); ++i) {
            depth += ((S[i] == '(') ? 1 : -1); 
            if(i > 0 && S[i - 1] == '(' && S[i] == ')')
                score += (1 << depth);
        }
        return score;
    }
};