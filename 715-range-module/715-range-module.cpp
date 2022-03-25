class RangeModule {
private:
    vector<pair<int, int>> intervals;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        vector<pair<int, int>> new_intervals;
        for(int i = 0; i <= intervals.size(); i++){
            if(i == intervals.size() || right < intervals[i].first){
                new_intervals.push_back({left, right});
                while(i < intervals.size()){
                    new_intervals.push_back(intervals[i]);
                    i++;
                }
            }
            else if(intervals[i].second < left)
                new_intervals.push_back(intervals[i]);
            else{
                if(intervals[i].first < left)
                    left = intervals[i].first;
                if(intervals[i].second > right)
                    right = intervals[i].second;
            }
        }
        swap(intervals, new_intervals);
    }
    
    bool queryRange(int left, int right) {
        int low = 0, high = intervals.size() - 1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(intervals[mid].second <= left)
                low = mid + 1;
            else if(right <= intervals[mid].first)
                high = mid - 1;
            else
                return (intervals[mid].first <= left &&
                            right <= intervals[mid].second);
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<pair<int, int>> new_intervals;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i].second <= left || right <= intervals[i].first)
                new_intervals.push_back(intervals[i]);
            else{
                if(intervals[i].first < left)
                    new_intervals.push_back({intervals[i].first, left});
                if(intervals[i].second > right)
                    new_intervals.push_back({right, intervals[i].second});
            }
        }
        swap(intervals, new_intervals);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */