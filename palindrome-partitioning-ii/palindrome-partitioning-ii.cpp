class Solution {
public:
    int is_string_palindrome(string& s, int l, int r, vector<vector<int>> &is_palindrome){
        if(l >= r)  return true;
        if(is_palindrome[l][r] != -1)   return is_palindrome[l][r];
        is_palindrome[l][r] = ((s[l] == s[r]) && is_string_palindrome(s, l + 1, r - 1, is_palindrome));
        return is_palindrome[l][r];
    }
    int get_min_cut(string& s, vector<vector<int>> &is_palindrome, vector<int>& min_cut, int current_index, int string_length){
        if(current_index >= string_length)  return 0;
        if(is_string_palindrome(s, current_index, string_length - 1, is_palindrome)) return 0;
        if(min_cut[current_index] != -1) return min_cut[current_index];
        min_cut[current_index] = INT_MAX;
        for(int cut_index = current_index; cut_index < string_length - 1; cut_index++){
            if(is_string_palindrome(s, current_index, cut_index, is_palindrome)){
                min_cut[current_index] = min(min_cut[current_index], 1 + get_min_cut(s, is_palindrome, min_cut, cut_index + 1, string_length));
            }
        }
        return min_cut[current_index];
    }
    int minCut(string s) {
        int l = s.length();
        vector<vector<int>> is_palindrome(l, vector<int>(l, -1));
        vector<int> min_cut(l, -1);
        return get_min_cut(s, is_palindrome, min_cut, 0, s.length());
    }
};