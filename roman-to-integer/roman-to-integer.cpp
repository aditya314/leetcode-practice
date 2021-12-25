class Solution {
private:
    unordered_map<char, int> roman_value;
    void generate_roman_value_map(){
        roman_value['I'] = 1;
        roman_value['V'] = 5;
        roman_value['X'] = 10;
        roman_value['L'] = 50;
        roman_value['C'] = 100;
        roman_value['D'] = 500;
        roman_value['M'] = 1000;
    }
public:
    int romanToInt(string s) {
        int n = s.length();
        if(n == 0) return -1;
        
        generate_roman_value_map();
        int answer = 0;
        for(int i = 0; i < n; i++){
            int curr_char_value = roman_value[s[i]];
            answer += ((i < n - 1) && curr_char_value < roman_value[s[i + 1]]) ? (-curr_char_value) : curr_char_value;
        }
        return answer;
    }
};