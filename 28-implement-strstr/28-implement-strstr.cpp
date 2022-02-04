class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m == 0)  return 0; 
        vector<int> LPS(m, 0);
            
        build_LPS_array(LPS, needle, m);
        
        int i = 0, j = 0;
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;    j++;
            }
            else{
                if(j != 0)  j = LPS[j - 1];
                else        i++;
            }
            if(j == m){
                return (i - j);
                j = LPS[j - 1];
            }  
        }
        return -1;
    }
private:
    void build_LPS_array(vector<int>& LPS, string& needle, int m){
        int len = 0, i = 1;
        while(i < m){
            if(needle[len] == needle[i]){
                LPS[i] = len + 1;
                len++;  i++;
            }
            else{
                if(len != 0)    len = LPS[len - 1];
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
};