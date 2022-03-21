class Solution {
    //catch case:
    //1949
    //4422
    //0A1B
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0, n = secret.length();
        unordered_map<char, int> char_freq;
        for(int i = 0; i < n; i++)
            char_freq[secret[i]]++;
        
        for(int i = 0; i < n; i++){
            if(char_freq.find(guess[i]) != char_freq.end()){
                if(guess[i] == secret[i]){
                    bulls++;
                    //secret[i] is used up, remove extra cow
                    if(char_freq[guess[i]] <= 0)
                        cows--;
                }
                else if(char_freq[guess[i]] > 0)
                    cows++;
                //used up
                char_freq[guess[i]]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};