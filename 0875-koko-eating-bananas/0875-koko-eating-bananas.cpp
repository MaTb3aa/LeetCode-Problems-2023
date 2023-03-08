class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9,cur=-1,md;
        while(l<=r){
            md=(l+r)>>1;
            long long time = 0;
            for(auto t : piles)
                time+=(t+md-1)/md;
            if(time<=h){
                r=md-1;cur=md;
            }
            else l=md+1;
        }
        return cur;
    }
};