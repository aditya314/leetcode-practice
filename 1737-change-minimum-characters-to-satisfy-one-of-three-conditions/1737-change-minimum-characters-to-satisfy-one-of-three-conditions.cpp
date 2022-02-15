class Solution {
private:
    int make_less(string& a, string& b){
        int min_changes = INT_MAX;
        for(char ch = 'b'; ch <= 'z'; ch++){
            int changes = 0;
            for(char ch_a : a)  
                changes += (ch_a >= ch);
            for(char ch_b : b)
                changes += (ch_b < ch);
            min_changes = min(min_changes, changes);
        }
        return min_changes;
    }
    int make_one_distinct(string& a, string& b){
        unordered_map<char, int> char_freq;
        for(char ch_a : a)  char_freq[ch_a]++;
        for(char ch_b : b)  char_freq[ch_b]++;
        
        int max_freq = INT_MIN;
        for(pair<char, int> freq : char_freq)
            max_freq = max(max_freq, freq.second);
        return a.length() + b.length() - max_freq;
    }
public:
    int minCharacters(string a, string b) {
        return min(min(make_less(a, b), make_less(b, a)), make_one_distinct(a, b));
    }
};