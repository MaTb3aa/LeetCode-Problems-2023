class Solution {
public:
    int n;
    const int  mod = 1e9+7;
    int dp [100005];
    int solve(int start,string &s, int &k){
        if(start==n) return 1; 
        
        int &ret = dp[start];
        if(~ret)return ret;
        ret = 0;
        long long curDigit = 0;
        
        for(int end = start ; end < n ; end++){
             curDigit = (curDigit * 10) + (s[end]-'0');
             if(curDigit > k || curDigit < 1 )break;
             ret = (ret%mod + solve(end+1,s,k)%mod) %mod ;
        }
        
        return ret%mod;
    }
    int numberOfArrays(string s, int k) {
       n = s.size();
        memset(dp,-1,sizeof dp);
       return solve(0,s,k);
        
    }
};