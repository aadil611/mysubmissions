class MyHashSet {
    private:
    // vector<bool> v;
    bool v[1000001]={false};
    public:
    MyHashSet() {
        // v.resize(1e6+1,false);
    }
    
    void add(int key) {
        v[key] = 1;
    }
    
    void remove(int key) {
        v[key] = 0;
    }
    
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */