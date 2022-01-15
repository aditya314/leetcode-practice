class Solution {
public:
    static bool cost_comparator(vector<int>& cost1, vector<int>& cost2){
        return (cost1[0] - cost1[1]) < (cost2[0] - cost2[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cost_comparator);
        int n = costs.size() / 2;
        int total_cost = 0;
        for(int i = 0; i < n; i++){
            total_cost += costs[i][0] + costs[i + n][1];
        }
        return total_cost;
    }
};