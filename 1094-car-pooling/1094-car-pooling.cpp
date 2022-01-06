class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> max_passenger_status(1001, 0);
        for(vector<int> trip :  trips){
            int passenger_count = trip[0];
            int from = trip[1];
            int to = trip[2];
            max_passenger_status[from] += passenger_count;
            max_passenger_status[to] -= passenger_count;
        }
        for(int i = 0; i < 1001; i++){
            if(i > 0)   max_passenger_status[i] += max_passenger_status[i - 1];
            if(max_passenger_status[i] > capacity)    return false;
        }
        return true;
    }
};