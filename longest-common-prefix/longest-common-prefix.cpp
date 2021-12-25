class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)  return "";
        
        string first_string = strs[0];
        int m = first_string.length();
        for(int i = 0; i < m; i++){
            char ch = first_string[i];
            for(int j = 1; j < n; j++){
                if(i >= strs[j].length() || strs[j][i] != ch){
                    return first_string.substr(0, i);
                }
            }
        }
        return first_string;
    }
};