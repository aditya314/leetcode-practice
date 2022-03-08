class Solution {
private:
    const vector<vector<string>> reversible_pairs = {
        {"0", "0"}, {"1", "1"}, {"6", "9"}, {"8", "8"}, {"9", "6"}
    };
    vector<string> get_n_strobogrammatic_numbers(int n, bool is_first_digit){
        if(n == 0)  return {""};
        if(n == 1)  return {"0", "1", "8"};
        vector<string> prev_nums = get_n_strobogrammatic_numbers(n - 2, false);
        vector<string> answer;
        for(string num : prev_nums){
            for(vector<string> reversible_pair : reversible_pairs){
                if(reversible_pair[0] == "0" && is_first_digit)
                    continue;
                // We can only append 0's if it is not first digit.
                answer.push_back(reversible_pair[0] + num + reversible_pair[1]);
            }
        }
        return answer;
    }
public:
    vector<string> findStrobogrammatic(int n) {
        return get_n_strobogrammatic_numbers(n, true);
    }
};