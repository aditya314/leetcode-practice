class Solution {
private:
    int get_min_taps(int n, vector<int>& ranges){
        int l = ranges.size(), tap_count = 0;
        for(int i = 0, end = 0, max_reach = 0; end < n; end = max_reach){
            tap_count++;
            while(i <= end){
                max_reach = max(max_reach, ranges[i]);
                i++;
            }
            if(end >= max_reach)    return -1;
        }
        return tap_count;
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> left_shift_ranges(n + 1, 0);
        int l = ranges.size();
        for(int i = 0; i < l; i++){
            if(ranges[i] > 0){
                int left = max(0, i - ranges[i]);
                left_shift_ranges[left] = max(left_shift_ranges[left], i + ranges[i]);
            }
        }
        
        return get_min_taps(n, left_shift_ranges);
    }
};