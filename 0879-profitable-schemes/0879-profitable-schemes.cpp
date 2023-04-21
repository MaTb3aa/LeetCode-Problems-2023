class Solution {
public:
    int sz;
    const int mod = 1e9+7;
    int dp[101][101][101];
    int solve(int idx,int RemN,int Remprofit,vector<int>& group, vector<int>& profit){
        if(RemN < 0)return 0;
        if(idx==sz)return Remprofit <= 0 && RemN >=0;
        int &ret = dp[idx][RemN][Remprofit];
        if(~ret)return ret;

        ret = 0;
        ret += solve(idx+1,RemN,Remprofit,group,profit)%mod;
        ret += solve(idx+1,RemN-group[idx],max(0,Remprofit-profit[idx]),group,profit)%mod;
        return ret;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        sz = group.size();
        memset(dp,-1,sizeof dp);
        return solve(0,n,minProfit,group,profit)%mod;
    }
};