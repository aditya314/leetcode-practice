class SnapshotArray {
private:
    int curr_snaps;
    vector<vector<pair<int, int>> > index_snaps;
    int get_value_for_index_given_snap(vector<pair<int,int>>& snaps, int snap_id){
        int low = 0, high = snaps.size() - 1, val = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(snaps[mid].first <= snap_id){
                val = snaps[mid].second;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return val;
    }
public:
    SnapshotArray(int length) {
        index_snaps = vector< vector<pair<int, int>> >(length);
        curr_snaps = 0;
    }
    
    void set(int index, int val) {
        if(index_snaps[index].empty() || index_snaps[index].back().first != curr_snaps)
            index_snaps[index].push_back({curr_snaps, val});
        else
            index_snaps[index].back().second = val;    
    }
    
    int snap() {
        return curr_snaps++;
    }
    
    int get(int index, int snap_id) {
        return get_value_for_index_given_snap(index_snaps[index], snap_id);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */