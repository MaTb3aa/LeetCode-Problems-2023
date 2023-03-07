class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0,r=1e15,cur=-1,md;
        while(l<=r){
            md=(l+r)>>1;
            long long cnt = 0 ;
            for(auto t : time){
                cnt+=md/t;
                if(cnt>=totalTrips){
                 break;
                }
            }
            
            if(cnt>=totalTrips){
                r=md-1;
                cur=md;
            }
            else l=md+1;
        }
        return cur;
    }
};