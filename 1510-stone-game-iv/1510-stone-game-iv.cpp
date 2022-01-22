class Solution {
private:
    bool get_winner(vector<int>& dp, int n){
        if(n == 0)  return false;
        if(dp[n] != -1)    return (dp[n] == 1) ? true :  false;
        for(int i = 1; i * i <= n; i++){
            if(!get_winner(dp, n - (i * i))){
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = 0;
        return (dp[n] == 1) ? true : false;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return get_winner(dp, n);
    }
};