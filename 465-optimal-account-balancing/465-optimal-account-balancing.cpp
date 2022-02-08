class Solution {
private:
   int settle_expense_with_min_transfer_backtrack(vector<int>& balances, int i){
       int n = balances.size();
       while(i < n && balances[i] == 0)     i++;
       int min_transfer = INT_MAX;
       for(int settle_index = i; settle_index < n; settle_index++){
           if(balances[settle_index] * balances[i] < 0){
               balances[settle_index] += balances[i];
               min_transfer = min(min_transfer,
                                  1 + settle_expense_with_min_transfer_backtrack(balances, i + 1));
               balances[settle_index] -= balances[i];
           }
       }
       return (min_transfer == INT_MAX) ? 0 : min_transfer;
   } 
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for(vector<int> transaction :  transactions){
            balance[transaction[0]] -= transaction[2];
            balance[transaction[1]] += transaction[2];
        }
        
        vector<int> non_settled_balances;
        for(pair<int,int> balance_info : balance)
            if(balance_info.second != 0)     
                non_settled_balances.push_back(balance_info.second);
        
        //set all balance to zero
        return settle_expense_with_min_transfer_backtrack(non_settled_balances, 0);
    }
};