class Solution {
private:
    vector<vector<int>> dp;
    bool can_cross(vector<int>& stones, unordered_map<int, int>& stones_index, int i, int jump, int n){
        if(dp[i][jump] != -1)  return dp[i][jump];
        if(i == n - 1) return true;
        for(int new_jump = jump - 1; new_jump <= jump + 1; new_jump++){
            int new_stone_value = stones[i] + new_jump;
            if(stones_index.find(new_stone_value) == stones_index.end())    continue;
            if(stones_index[new_stone_value] > i &&
                can_cross(stones, stones_index, stones_index[new_stone_value], new_jump, n)){
                dp[i][jump] = true;
                return true;
            }
        }
        dp[i][jump] = false;
        return false;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        dp.assign(n, vector<int>(n, -1));
        unordered_map<int, int> stones_index;
        for(int i = 0; i < n; i++){
            stones_index[stones[i]] = i;
        }
        return can_cross(stones, stones_index, 0, 0, n);
    }
};