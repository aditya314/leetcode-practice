class Solution {
    static bool interval_comparator(vector<int>& i1, vector<int>& i2){
        return (i1[0] == i2[0]) ? (i1[1] > i2[1]) : (i1[0] < i2[0]);
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), unique_intervals = 0;
        sort(intervals.begin(), intervals.end(), interval_comparator);
        vector<int> prev_interval;
        for(int i = 0; i < n; i++){
            if(prev_interval.size() == 2 &&
                    prev_interval[0] <= intervals[i][0] && intervals[i][1] <= prev_interval[1])
                    continue;
            else{
                unique_intervals++;
                prev_interval = intervals[i];
            } 
        }
        return unique_intervals;
    }
};