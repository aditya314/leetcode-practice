class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        for(vector<int> bank_accounts : accounts){
            int total_wealth = 0;
            for(int balance :  bank_accounts)   total_wealth += balance;
            max_wealth = max(max_wealth, total_wealth);
        }
        return max_wealth;
    }
};