// class LRUCache {
// private:
//     int cache_capacity;
//     list<pair<int,int>> cache;
//     unordered_map<int, list<pair<int,int>>::iterator > cache_map;
// public:
//     LRUCache(int capacity) {
//         cache_capacity = capacity;
//     }
    
//     int get(int key) {
//         unordered_map<int, list<pair<int,int>>::iterator >::iterator found_itr = cache_map.find(key);
//         if(found_itr != cache_map.end()){
//             cache.splice(cache.begin(), cache, found_itr -> second);
//             return found_itr->second->second;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         unordered_map<int, list<pair<int,int>>::iterator >::iterator found_itr = cache_map.find(key);
//         if(found_itr != cache_map.end()){
//             cache.splice(cache.begin(), cache, found_itr -> second);
//             found_itr->second->second = value;
//             return;
//         }
//         if(cache.size() == cache_capacity){
//             int key_to_delete = cache.back().first;
//             cache.pop_back();
//             cache_map.erase(key_to_delete);
//         }
//         cache.emplace_front(key, value);
//         cache_map[key] = cache.begin();
//     }
// };
class DLLNode{
public:
    int key, value;
    DLLNode *prev, *next;
    
    DLLNode(int key, int value){
        this->key = key;
        this->value = value;
    }
};
class LRUCache {
private:
    int cache_capacity;
    int size;
    DLLNode *cache_head, *cache_tail;
    unordered_map<int, DLLNode*> cache_map;
    void remove_from_cache(DLLNode* node){
        DLLNode *previous_node = node -> prev, *next_node = node -> next;
        previous_node -> next = next_node;
        next_node -> prev = previous_node;
    }
    void add_to_cache_head(DLLNode* node){
        node -> prev = cache_head;
        node -> next = cache_head -> next;
        cache_head -> next -> prev = node;
        cache_head -> next = node;
    }
    void move_to_cache_head(DLLNode* node){
        remove_from_cache(node);
        add_to_cache_head(node);
    }
    DLLNode* evict_from_cache(){
        DLLNode* evicted_node = cache_tail->prev;
        remove_from_cache(evicted_node);
        return evicted_node;
    }
public:
    LRUCache(int capacity) {
        cache_capacity = capacity;
        size = 0;
        cache_head = new DLLNode(-1, -1);
        cache_tail = new DLLNode(-1, -1);
        cache_head -> next = cache_tail;
        cache_tail -> prev = cache_head;
    }
    
    int get(int key) {
        DLLNode* node = cache_map[key];
        if(node == NULL)    return -1;
        move_to_cache_head(node);
        return node -> value;
    }
    
    void put(int key, int value) {
        DLLNode* node = cache_map[key];
        if(node == NULL){
            if(size == cache_capacity){
                node = evict_from_cache();
                cache_map.erase(node -> key);
                size--;
            }
            node = new DLLNode(key, value);
            add_to_cache_head(node);
            cache_map[key] = node;
            size++;
        } 
        else{
            node->value = value;
            move_to_cache_head(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */