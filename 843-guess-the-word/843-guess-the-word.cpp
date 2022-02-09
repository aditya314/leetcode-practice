/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    int get_char_match_count(string a, string b){
        int matches = 0;
        for(int i = 0; i < a.size(); i++)
            if(a[i] == b[i])    matches++;
        return matches;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        //random_shuffle(wordlist.begin(), wordlist.end());
        for (int i = 0; i < 10; ++i) {
            //string guess = wordlist[0];
            string guess = wordlist[rand() % (wordlist.size())];
            int char_match = master.guess(guess);
            vector<string> narrowed_wordlist;
            for (string w : wordlist)
                if (get_char_match_count(guess, w) == char_match)
                        narrowed_wordlist.push_back(w);
            swap(wordlist, narrowed_wordlist);
        }
    }
};