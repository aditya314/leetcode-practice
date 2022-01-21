class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int answer_station = 0, total_tank = 0, curr_tank = 0;
        for(int i = 0; i < n; i++){
            int travel_cost = gas[i] - cost[i];
            total_tank += travel_cost;
            curr_tank += travel_cost;
            if(curr_tank < 0){
                answer_station = i + 1;
                curr_tank = 0;
            }
        }
        return (total_tank >= 0) ? answer_station : -1;
    }
};