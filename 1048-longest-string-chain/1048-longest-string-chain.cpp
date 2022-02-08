class Solution {
private:
    bool can_make_chain(string& a, string& b){
        int i = 0, j = 0, n = a.size(), m = b.size(), mismatch = 0;
        if(m - n != 1)  return false;
        while(i < n && j < m){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                mismatch++;
                j++;
            }
            if(mismatch > 1)    return false;
        }
        return true;
    }
    static bool word_length_comparator(string& a, string& b){
        return (a.size() < b.size());
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int answer = 1;
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), word_length_comparator);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                //cout<<"For word "<<words[i]<<" "<<words[j]<<endl;
                if(can_make_chain(words[i], words[j])){
                    //cout<<"Can make chain"<<endl;
                    dp[j] = max(dp[j], dp[i] + 1);
                    answer = max(answer, dp[j]);
                }
            }
        }
        return answer;
    }
};