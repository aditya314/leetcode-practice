class Solution {
public:
    static bool cost_savings_for_city_A_comparator(const vector<int>& cost1, const vector<int>& cost2){
        int savings1 = cost1[0] - cost1[1], savings2 = cost2[0] - cost2[1];
        return (savings1 < savings2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cost_savings_for_city_A_comparator);
        
        int total_cost = 0, n = costs.size() / 2;
        //first n got to city A, next n got to city B
        for(int i = 0; i < n; i++)
            total_cost += (costs[i][0] + costs[i + n][1]);
        return total_cost;
    }
};
