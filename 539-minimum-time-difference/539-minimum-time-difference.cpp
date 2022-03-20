class Solution {
private:
    int time_point_to_minute(string s){
        int hour = (s[0] - '0') * 10 + (s[1] - '0');
        int minute = (s[3] - '0') * 10 + (s[4] - '0');
        return hour * 60 + minute;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> minute_mark(24 * 60, false);
        int min_time = INT_MAX, max_time = INT_MIN;
        for(string time_point : timePoints){
            int minute = time_point_to_minute(time_point);
            if(minute_mark[minute]) return 0;
            minute_mark[minute] = true;
            if(minute < min_time)
                min_time = minute;
            if(minute > max_time)
                max_time = minute;
        }
        
        int prev = 0, min_diff = INT_MAX;
        for(int curr_time = min_time; curr_time <= max_time; curr_time++){
            if(minute_mark[curr_time]){
                //0---min_time----max_time-----1440, 
                //so we have two directions to calculate the distance
                if(curr_time == min_time)
                    min_diff = min(min_diff, min(max_time - min_time,
                                    (min_time - 0) + (1440 - max_time)));
                else
                    min_diff = min(min_diff, curr_time - prev);
                prev = curr_time;
            }
        }
        return min_diff;
    }
};