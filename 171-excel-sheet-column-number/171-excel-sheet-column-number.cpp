class Solution {
public:
    int titleToNumber(string s) {
        int col_num = 0;
        for(char ch : s)   col_num = col_num * 26 + (ch - 'A') + 1;
        return col_num;
    }
};