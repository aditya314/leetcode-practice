class Solution {
private:
    unordered_map<char, string> keypad_map 
        = {{'2', "abc"}, {'3', "def"},
           {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
           {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> all_combos;
        if(digits.length() == 0)    return all_combos;
        all_combos.push_back("");
	    for(char digit : digits){
		    vector<string> extend_combos;
		    for(string curr_combo : all_combos){
			    for(char letter : keypad_map[digit]){
                    extend_combos.push_back(curr_combo + letter);
                }
            }
		    swap(all_combos, extend_combos);
            // same as all_combos = extend_combos, just avoids copying each value
	    }
	    return all_combos;
    }
};