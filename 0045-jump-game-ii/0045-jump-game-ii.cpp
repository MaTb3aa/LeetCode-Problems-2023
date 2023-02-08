class Solution {
public:
    int n;
    int dp[10004];
    int solve(int idx,vector<int>& nums){
        if(idx>=n-1)return 0;
        int &ret = dp[idx];
        if(~ret)return ret;
        ret = 1e9;
        for(int i=1;i<=nums[idx];i++){
            ret=min(ret,solve(idx+i,nums)+1);
        }
        return ret;
        
    }
    int jump(vector<int>& nums) {
         n = nums.size();
         memset(dp,-1,sizeof dp);
         return solve(0,nums);
    }
};