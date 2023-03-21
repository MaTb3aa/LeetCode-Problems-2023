class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0  , ans = 0;
        for(auto t : nums){
            if(!t)cnt++;
            else {
                ans+=cnt*(cnt+1)/2;
                cnt=0;
            }
        }
        ans+=cnt*(cnt+1)/2;
        return ans;
        
    }
};