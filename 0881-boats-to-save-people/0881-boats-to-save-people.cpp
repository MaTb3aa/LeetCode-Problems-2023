class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int st = 1 , ed = 1e9, cur = -1 , md;
        multiset<int>mst;
        
        for(auto t : people)mst.insert(t);
        
        int cnt = 0;
        while(mst.size()){
            int cur = *mst.begin();
            mst.erase(mst.begin());
            if(mst.size()){
                auto it = mst.lower_bound(limit-cur);
               if(it==mst.end() || *it + cur > limit)it--;
                if(it!=mst.end() && cur + *it <=limit){
                    mst.erase(it);
                }
            }
            cnt++;
        }
        return cnt;
    }
};