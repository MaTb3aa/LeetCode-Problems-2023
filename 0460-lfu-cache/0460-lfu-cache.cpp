class LFUCache {
public:
    int mp[100005],freq[100005],lstUpdate[100005],sz,time;
    set<pair<pair<int,int>,int>>st;
    LFUCache(int capacity) {
        memset(mp,-1,sizeof mp);
        memset(freq,0,sizeof freq);
        memset(lstUpdate,0,sizeof lstUpdate);
        sz = capacity;
        time = 0 ;
        st.clear();
    }
    
    int get(int key) {
        if(~mp[key]){
            auto it = st.find({{freq[key],lstUpdate[key]},key});
            freq[key]++;
            lstUpdate[key]=++time;
            st.erase(it);
            st.insert({{freq[key],lstUpdate[key]},key});
            return mp[key]; 
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(~mp[key]){
            auto it = st.find({{freq[key],lstUpdate[key]},key});
            freq[key]++;
            lstUpdate[key]=++time;
            st.erase(it);
            mp[key]=value;
            st.insert({{freq[key],lstUpdate[key]},key});
            return ;
        }
        if(st.size() == sz && sz ){
            auto it = st.begin();
            mp[(*it).second]= -1;
            freq[(*it).second] = 0;
            lstUpdate[(*it).second]=0;
            st.erase(it);
        }
        if(st.size() < sz){
            mp[key] = value;
            freq[key]++;
            lstUpdate[key]=++time;
            st.insert({{freq[key],lstUpdate[key]},key});
        }
        
     
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */