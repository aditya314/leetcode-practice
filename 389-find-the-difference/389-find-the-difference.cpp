class Solution {
public:
    char findTheDifference(string s, string t) {
        char diff_ch = 0;
        for(char ch : s)    diff_ch ^= ch;
        for(char ch : t)    diff_ch ^= ch;
        return diff_ch;
    }
};