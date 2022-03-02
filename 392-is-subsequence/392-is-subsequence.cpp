class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j, n = s.length(), m = t.length();
        for(int j = 0; i < n && j < m; j++){
            if(s[i] == t[j])   i++;
        }
        return (i == n);
    }
};