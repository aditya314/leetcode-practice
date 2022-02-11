class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m)   return false;
        
        unordered_map<char, int> s1_char_freq;
        for(char ch :  s1)
            s1_char_freq[ch]++;
        
        unordered_map<char, int> substr_freq;
        for(int i = 0; i < n; i++)
            substr_freq[s2[i]]++;
        
        if(s1_char_freq == substr_freq)     return true;
        for(int i = n; i < m; i++){
            substr_freq[s2[i]]++;
            substr_freq[s2[i - n]]--;
            if(substr_freq[s2[i - n]] == 0)
                substr_freq.erase(s2[i - n]);
            if(s1_char_freq == substr_freq)     return true;
        }
        return false;
    }
};