class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[n][m - 1] = dp[n - 1][m] = 1;
        //dp[i][j] health required to land on (i, j)
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int required_health_to_go_ahead = min(dp[i + 1][j], dp[i][j + 1]);
                int health_required_before_coming = required_health_to_go_ahead - dungeon[i][j];
                if(health_required_before_coming <= 0)
                    health_required_before_coming = 1;
                dp[i][j] = health_required_before_coming;
            }
        }
        return dp[0][0];
    }
};