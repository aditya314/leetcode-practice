vector< vector<int> > isPalindromeSubstring(1000, vector<int>(1000));

class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        if(l == 0)  return s;
        
        string longestPalindrome;
        for(int i = l - 1; i >= 0; i--){
            for(int j = i; j < l; j++){
                isPalindromeSubstring[i][j] = (s[i] == s[j]) && 
                    ((j - i <= 2) || isPalindromeSubstring[i+1][j-1]);
                if(isPalindromeSubstring[i][j] &&
                   (longestPalindrome.empty() || (longestPalindrome.length() < (j - i + 1)))){
                longestPalindrome = s.substr(i, j - i + 1);
                }
            }
                                                                 
        }
        return longestPalindrome;
    }
};