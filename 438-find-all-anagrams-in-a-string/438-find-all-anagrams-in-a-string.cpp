class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> anagram_pos;
        unordered_map<char, int> char_freq;
        for(char ch : p)    char_freq[ch]++;
        unordered_map<char, int> substring_freq;
        for(int i = 0; i < n; i++){
            substring_freq[s[i]]++;
            if(i >= m){
                if(substring_freq[s[i - m]] == 1)   substring_freq.erase(s[i - m]);
                else    substring_freq[s[i - m]]--;
            }
            if(substring_freq == char_freq)     anagram_pos.push_back(i - m + 1);
        }
        return anagram_pos;
    }
};