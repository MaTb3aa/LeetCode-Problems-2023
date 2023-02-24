class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        multiset<int>mst;
        for(auto t : nums)mst.insert(t);
        int ans = 1e9;
        while(true){
            ans = min(ans,abs((*(--mst.end())) -(*mst.begin()) ));
            int x = *mst.begin();
            if(x&1){
                 x*=2;
                mst.erase(mst.begin());
                mst.insert(x);
            }
            else break;
            
        }
        while(true){
                        ans = min(ans,abs((*(--mst.end())) -(*mst.begin()) ));

            int x = *(--mst.end());
            if( !(x&1) ){
                x/=2;
                mst.erase(prev(mst.end()));
                mst.insert(x);
            }
            else break;
        }
                    ans = min(ans,abs((*(--mst.end())) -(*mst.begin()) ));

        return ans;
    }
};