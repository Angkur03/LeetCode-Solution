class MyHashMap {
public:
    int mapValue[1000001];
    MyHashMap() {
        memset(mapValue,-1,sizeof(mapValue));
    }
    
    void put(int key, int value) {
        mapValue[key]=value;
    }
    
    int get(int key) {
        return mapValue[key];
    }
    
    void remove(int key) {
        mapValue[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */