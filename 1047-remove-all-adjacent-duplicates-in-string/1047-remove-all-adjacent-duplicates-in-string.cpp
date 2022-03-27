class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(!st.empty() && st.back() == s[i])
                st.pop_back();
            else
                st.push_back(s[i]);
        }
        string answer(st.begin(), st.end());
        return answer;
    }
};