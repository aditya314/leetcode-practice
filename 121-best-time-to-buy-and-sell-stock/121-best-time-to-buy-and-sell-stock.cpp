class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if(days <= 1)   return 0;
        
        int minBuyCost = prices[0], profit = 0;
        for(int i = 1; i < days; i++){
            if(prices[i] > minBuyCost)
                profit = max(profit, prices[i] - minBuyCost);
            else
                minBuyCost = prices[i];
        }
        
        return profit;
    }
};

