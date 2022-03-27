class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> count_stack;
        for(int i = 0 ; i < s.length(); i++){
            if(count_stack.empty() || count_stack.back().first != s[i])
                count_stack.push_back({s[i], 1});
            else if(++count_stack.back().second == k)
                count_stack.pop_back();
        }
        
        string answer = "";
        for(pair<char, int>& char_freq : count_stack)
            answer += string(char_freq.second, char_freq.first);
        return answer;
    }
};