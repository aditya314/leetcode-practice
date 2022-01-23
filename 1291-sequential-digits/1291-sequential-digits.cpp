class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string sequential_digit_generator = "123456789";
        vector<int> answer;
        int min_len = to_string(low).length(), max_len = to_string(high).length();
        for(int l = min_len; l <= max_len; l++){
            for(int start = 0; start < (10 - l); start++){
                int num = stoi(sequential_digit_generator.substr(start, l));
                if(num >= low && num <= high)   answer.push_back(num);
            }
        }
        return answer;
    }
};