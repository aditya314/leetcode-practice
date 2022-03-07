class Solution {
private:
   int get_max_coins(vector<int>& nums, int i, int j, vector<vector<int>>& max_coins){
       if(i > j)    return 0;
       if(max_coins[i][j] != -1)    return max_coins[i][j];
       int max_coin_value = INT_MIN;
       for(int k = i ; k <= j; k++){
           int coin_for_split_at_k = get_max_coins(nums, i, k - 1, max_coins) + (nums[i - 1] * nums[k] * nums[j + 1]) + get_max_coins(nums, k + 1, j, max_coins);
           max_coin_value = max(max_coin_value, coin_for_split_at_k);
       }
       max_coins[i][j] = max_coin_value;
       return max_coin_value;
   } 
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        //dp[i][j] in here means, the maximum coins we get after we burst all the balloons between i and j in the original array.
        vector<vector<int>> max_coins(n, vector<int>(n, -1));
        return get_max_coins(nums, 1, n - 2, max_coins);
    }
};