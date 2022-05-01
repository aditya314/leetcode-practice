class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        int i = n - 1, j = m - 1, s_backspace = 0, t_backspace = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    s_backspace++;  i--;
                }
                else if(s_backspace > 0){
                    s_backspace--;  i--;
                }
                else    break;
            }
            
            while(j >= 0){
                if(t[j] == '#'){
                    t_backspace++;  j--;
                }
                else if(t_backspace > 0){
                    t_backspace--;  j--;
                }
                else    break;
            }
            
            if(i >= 0 && j >= 0 && s[i] != t[j])
                return false;
            if((i >= 0 && j < 0) || (i < 0 && j >= 0))
                return false;
            i--;    j--;
        }
        return true;
    }
};