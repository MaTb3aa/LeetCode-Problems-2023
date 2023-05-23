class KthLargest {
private:
    multiset<int>mst;
    int kk;
public:
    
    KthLargest(int k, vector<int>& nums) {
        for(auto t : nums)mst.insert(t);
        kk = k ;
        while(mst.size() > k)mst.erase(mst.begin());
    }
    
    int add(int val) {
       mst.insert(val);
       if(mst.size()>kk)mst.erase(mst.begin());
       return *mst.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */