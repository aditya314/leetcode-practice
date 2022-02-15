class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int substring_count = 0, n = s.length();
        int start = 0, end = 0;
        unordered_map<char, int> char_freq;
        while(end < n){
            char_freq[s[end]]++;
            while(char_freq[s[end]] > 1){
                char_freq[s[start]]--;
                start++;
            }
            if(end - start + 1 == k){
                substring_count++;
                //This is done so that the size of the window does not exceed kk.
                char_freq[s[start]]--;
                start++;
            }
            end++;
        }
        return substring_count;
    }
};