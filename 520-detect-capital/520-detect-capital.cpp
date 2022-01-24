class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1)  return true;
        if(isupper(word[0]) && isupper(word[1])){
            //remaining letters should be capital
            for(int i = 2; i < n; i++){
                if(islower(word[i]))    return false;
            }
        }
        else{
            //remaining letters should be small
            for(int i = 1; i < n; i++){
                if(isupper(word[i]))    return false;
            }
        }
        return true;
    }
};