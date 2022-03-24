class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_set<string> regex_set;
        
        for(string word : dict) {
            string regex = word;
            for(int i = 0; i < word.size(); i++) {
                //resetting previous '*'
                if(i > 0) 
                    regex[i - 1] = word[i - 1];
                regex[i] = '*';
                if(regex_set.count(regex))
                    return true;
                regex_set.insert(regex);
            }
        }
        return false;
    }
};