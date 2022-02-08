class Solution {
private:
   int settle_expense_with_min_transfer_backtrack(vector<int>& balances, int settle_index){
       int n = balances.size();
       while(settle_index < n && balances[settle_index] == 0)     settle_index++;
       int min_transfer = INT_MAX;
       for(int j = settle_index; j < n; j++){
           if(balances[settle_index] * balances[j] < 0){
               balances[j] += balances[settle_index];
               min_transfer = min(min_transfer,
                                  1 + settle_expense_with_min_transfer_backtrack(balances, settle_index + 1));
               balances[j] -= balances[settle_index];
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