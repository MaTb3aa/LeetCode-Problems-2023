class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        multiset<int>mst;
        for(auto t : nums)mst.insert(t);
        
        int ans = 1e9;
        for(int i = 0 ; i < 3e6 ; i++){
            ans = min (ans,abs((*(--mst.end())) -(*mst.begin()) ));
            int a = *mst.begin();
            if(a&1){
                 a*=2;
                 mst.erase(mst.begin());
                mst.insert(a);
            }
            else break;
            
        }
         for(int i = 0 ; i < 3e6 ; i++){
            ans = min (ans,abs((*(--mst.end())) -(*mst.begin()) ));
            int b = *(--mst.end());
            if( !(b&1) ){
                b/=2;
                mst.erase(prev(mst.end()));
                mst.insert(b);
            }
            else break;
            
        }
        return ans;
    }
};