vector< vector<bool> > is_palindrome;
vector< vector<string> > answer;
class Solution {
public:
    void get_palindrome_partitions(string s, int i, vector<string> partitions){
        if(i >= s.length()){
            answer.push_back(partitions);
        }
        else{
            for(int j = i; j < s.length(); j++){
                if(s[i] == s[j] && (j - i <= 2 || is_palindrome[i + 1][j - 1])){
                    is_palindrome[i][j] = true;
                    partitions.push_back(s.substr(i, j - i + 1));
                    get_palindrome_partitions(s, j + 1, partitions);
                    partitions.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        is_palindrome = vector< vector<bool> >(s.length(), vector<bool>(s.length(), false));
        answer.clear();
        vector<string> partitions;
        get_palindrome_partitions(s, 0, partitions);
        return answer;
    }
};