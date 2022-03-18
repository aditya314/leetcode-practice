class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        unordered_map<char, int> last_occourence;
        for(int i = 0; i < n; i++)
               last_occourence[s[i]] = i;         

        vector<char> st;
        unordered_set<char> in_stack;
        for(int i = 0; i < n; i++){
            if(in_stack.find(s[i]) == in_stack.end()){
                while(st.size() && st.back() > s[i]
                            && last_occourence[st.back()] > i){
                    in_stack.erase(st.back());
                    st.pop_back();
                }
                in_stack.insert(s[i]);
                st.push_back(s[i]);
            }
        }
        string answer(st.begin(), st.end());
        return answer;
    }
};