class Solution {  
private:
    static const long MOD = 10e9 + 7;
    static const long random_prime = 101;
    long modular_exponentiation(long base, long power){
        long res = 1;
        while(power > 0){
            if(power & 1) res = (res * base) % MOD;
            power = power >> 1;
            base = (base * base) % MOD;
        }
        return res;
    }
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char, int> window_count;
        unordered_map<string, int> string_occurence;
        int start = 0, max_freq = 0;
        // long hash = 0, hash_rollback = modular_exponentiation(random_prime, minSize - 1) % MOD;
        for(int end = 0; end < s.length(); end++){
            window_count[s[end]]++;
            // hash = (hash % MOD * random_prime + (s[end] - 'a')) % MOD;
            if((end - start + 1) > minSize){
                //hash = (hash % MOD -  ((s[start] - 'a') * hash_rollback) % MOD) % MOD;
                window_count[s[start]]--;
                if(window_count[s[start]] == 0)   window_count.erase(s[start]);
                start++;
            }
            if((end - start + 1) == minSize && window_count.size() <= maxLetters)
                max_freq = max(max_freq, ++string_occurence[s.substr(start,end - start + 1)]);
        }
        return max_freq;
    }
};