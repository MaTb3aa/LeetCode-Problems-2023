class Solution {
public:
    int n;
    const int mod = 1e9+7;
    int dp[100005];
    int solve(int idx,string &s,int &k){
        if(idx==n)return 1;
        int &ret = dp[idx];
        if(~ret)return ret;
        ret = 0;
        long long cur = 0 ;
        for(int i = idx; i < n ;i++){
            cur = cur * 10 + (s[i]-'0');
            if(cur< 1 || cur > k)break;
            ret= (ret + (solve(i+1,s,k))%mod)%mod;
        }
        return ret%mod;
    }
    int numberOfArrays(string s, int k) {
        n = s.size();
        memset(dp,-1,sizeof dp);
        return solve(0,s,k);
    }
};