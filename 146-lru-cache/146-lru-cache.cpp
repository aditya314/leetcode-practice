class LRUCache {
private:
    int cache_capacity;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator > cache_map;
public:
    LRUCache(int capacity) {
        cache_capacity = capacity;
    }
    
    int get(int key) {
        unordered_map<int, list<pair<int,int>>::iterator >::iterator found_itr = cache_map.find(key);
        if(found_itr != cache_map.end()){
            cache.splice(cache.begin(), cache, found_itr -> second);
            return found_itr->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        unordered_map<int, list<pair<int,int>>::iterator >::iterator found_itr = cache_map.find(key);
        if(found_itr != cache_map.end()){
            cache.splice(cache.begin(), cache, found_itr -> second);
            found_itr->second->second = value;
            return;
        }
        if(cache.size() == cache_capacity){
            int key_to_delete = cache.back().first;
            cache.pop_back();
            cache_map.erase(key_to_delete);
        }
        cache.emplace_front(key, value);
        cache_map[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */