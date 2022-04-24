class MyHashMap {
public:
    vector<list<pair<int,int>>> vl;
    int size = 1000;
    
    MyHashMap() {
        vl.resize(size);
    }
    
    int hash(int key) {
        return key % size;
    }
    
    list<pair<int,int>> :: iterator getIterator(int hashed_key,int key) {
        list<pair<int,int>> :: iterator it;
        for(it = vl[hashed_key].begin(); it != vl[hashed_key].end(); ++it) 
            if(it->first == key)
                return it;
        return vl[hashed_key].end();
    }
    
    void put(int key, int value) {
        int i = hash(key);
        auto it = getIterator(i,key);
        if(it != vl[i].end())
            it->second = value;
        else
            vl[i].push_back(pair<int,int>(key,value));   
    }
    
    int get(int key) {
        int i = hash(key);
        auto it = getIterator(i,key);
        if(it != vl[i].end())
           return it->second;
        return -1;
    }
    
    void remove(int key) {
        int i = hash(key);
        auto it = getIterator(i,key);
        if(it != vl[i].end())
            vl[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */