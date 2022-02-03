class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), max_len = 0;
        unordered_map<char, int> char_index;
        int start = 0, end = 0;
        while(end < n){
            if(char_index.find(s[end]) != char_index.end())
                start = max(start, char_index[s[end]] + 1);
            max_len = max(max_len, end - start + 1);
            char_index[s[end]] = end;
            end++;
        }
        return max_len;
    }
};