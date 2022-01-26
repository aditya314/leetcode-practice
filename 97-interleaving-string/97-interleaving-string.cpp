class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), p = s3.length();
        if(m + n != p)  return false;
        vector<vector<bool>> can_interleave(m + 1, vector<bool>(n + 1, false));
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 && j == 0)    can_interleave[i][j] = true;
                else if(i == 0)         can_interleave[i][j] = can_interleave[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                else if(j == 0)         can_interleave[i][j] = can_interleave[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                else
                    can_interleave[i][j] = (can_interleave[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (can_interleave[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }
        return can_interleave[m][n];
    }
};