class Solution {
private:
    //Time complexity: O(NMlogM) + O(N^2logN)
    int get_manhattan_distance(vector<int> source, vector<int> destination){
        return abs(destination[0] - source[0]) + abs(destination[1] - source[1]);
    }
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<tuple<int, int, int>>> worker_bike_options;
        priority_queue<tuple<int, int, int>,
            vector<tuple<int, int, int>> , greater<tuple<int, int, int>>> pq;
        
        for(int worker_index = 0; worker_index < workers.size(); worker_index++){
            vector<tuple<int, int, int>> bike_options;
            for(int bike_index = 0; bike_index < bikes.size(); bike_index++){
                int manhatten_distance =
                    get_manhattan_distance(workers[worker_index], bikes[bike_index]);
                bike_options.push_back({manhatten_distance, worker_index, bike_index});
            }
            sort(bike_options.begin(), bike_options.end(), greater<tuple<int, int, int>>());
            pq.push(bike_options.back());
            bike_options.pop_back();
            worker_bike_options.push_back(bike_options);
        }
        
        vector<bool> is_bike_reserved(bikes.size(), false);
        vector<int> worker_bike_assignment(workers.size(), -1);
        while(!pq.empty()){
            auto[manhatten_distance, worker_index, bike_index] = pq.top();
            pq.pop();
            if(!is_bike_reserved[bike_index]){
                is_bike_reserved[bike_index] = true;
                worker_bike_assignment[worker_index] = bike_index;
            }
            else{
                pq.push(worker_bike_options[worker_index].back());
                worker_bike_options[worker_index].pop_back();
            }
        }
        return worker_bike_assignment;
    }
};