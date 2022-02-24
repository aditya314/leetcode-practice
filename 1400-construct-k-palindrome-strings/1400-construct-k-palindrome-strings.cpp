class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> char_freq;
        for(char ch : s)
            char_freq[ch]++;
        int odd_count = 0;
        for(pair<char, int> p :  char_freq){
            if(p.second & 1)
                odd_count++;
        }
        return (odd_count <= k && k <= s.length());
    }
};