class Solution {
public:
    long long dp[100005];
    int mod = 1e9+7;
    long long solve(int len,int low, int high, int zero, int one){
        if(len > high)return 0;
      
        long long &ret = dp[len];
        if(~ret) return ret;
         ret = 0;

        if(len>=low && len <=high)ret = 1;
        ret += solve(len+zero,low,high ,zero,one)%mod;
        ret += (solve(len+one,low,high ,zero,one)%mod);
        return ret%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof dp);
        return solve(0,low,high,zero,one);
    }
};