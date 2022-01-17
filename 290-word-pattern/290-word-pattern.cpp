class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> char_index_map;
        unordered_map<string, int> str_index_map;
        istringstream sin(s);
        string word;
        int i = 0, n = pattern.size();
        while(sin >> word){
            if(i == n || str_index_map[word] != char_index_map[pattern[i]])
                return false;
            str_index_map[word] = char_index_map[pattern[i]] = i + 1;
            i++;
        }
        return (i == n);
    }
};