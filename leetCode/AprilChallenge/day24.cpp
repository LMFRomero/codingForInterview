class LRUCache {
private:   
    int capacity;
    queue<int> last_used;
    map<int, int> in_queue;
    map<int, int> key_map;
    
    void add_to_queue(int key) {
        last_used.push(key);
        in_queue[key]++;
    }
    
public:
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
        auto it = key_map.find(key);
        
        if (it == key_map.end())
            return -1;
        
        add_to_queue(key);
        return it->second;
    }
    
    void put(int key, int value) {
        if (key_map.size() < capacity) {
            add_to_queue(key);
            key_map[key] = value;
            return;
        }
        
        if (key_map.find(key) != key_map.end()) {
            add_to_queue(key);
            key_map[key] = value;
            return;
        }
          
        while (true) {
            int next = last_used.front();
            last_used.pop();

            if (--in_queue[next] == 0) {
                key_map.erase(next);
                break;
            }
        }
        
        add_to_queue(key);
        key_map[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
