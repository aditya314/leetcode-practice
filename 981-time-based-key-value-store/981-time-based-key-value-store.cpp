class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>> > k_v_store;
    string get_latest_time_entry(vector<pair<int,string>>& time_values, int timestamp){
        int low = 0, high = time_values.size() - 1;
        string value = "";
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(time_values[mid].first <= timestamp){
                low = mid + 1;
                value = time_values[mid].second;
            }
            else{
                high = mid - 1;
            }
        }
        return value;
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        //All the timestamps timestamp of set are strictly increasing.
        //use ordered_map to get sorted insert
        k_v_store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(k_v_store.find(key) == k_v_store.end())  return "";
        return get_latest_time_entry(k_v_store[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */