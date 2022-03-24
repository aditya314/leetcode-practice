class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_set<string> regex_set;
        
        for(string word : dict) {
            string regex = word;
            for(int i = 0; i < word.size(); i++) {
                regex[i] = '*';
                if(regex_set.find(regex) != regex_set.end())
                    return true;
                regex_set.insert(regex);
                //resetting the '*'
                regex[i] = word[i];
            }
        }
        return false;
    }
};