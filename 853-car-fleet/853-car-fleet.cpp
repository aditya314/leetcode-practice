class Solution {
public:
    static bool car_position_comparator(pair<int, int>& car1, pair<int, int>& car2){
        return (car1.first > car2.first);
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), car_position_comparator);
        double curr_max_time = 0.0;
        int car_fleet_size = 0;
        for(int i = 0; i < n; i++){
            double time_to_reach = (target - cars[i].first) / (cars[i].second * 1.0);
            if(time_to_reach > curr_max_time){
                curr_max_time = time_to_reach;
                car_fleet_size++;
            }
        }
        return car_fleet_size;
    }
};