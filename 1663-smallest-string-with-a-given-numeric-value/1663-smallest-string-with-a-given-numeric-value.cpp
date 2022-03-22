class Solution {
public:
    string getSmallestString(int n, int k) {
        string answer(n, 'a');
        k -= n;
        //set all with minimum 'a', now try to fill 'z' from right side greedily
        for(int i = n - 1; i >= 0 && k > 0; i--){
            int curr_char_addition = min(k, 'z' - 'a');
            answer[i] = (char)(answer[i] + curr_char_addition);
            k -= curr_char_addition;
        }
        return answer;
    }
};