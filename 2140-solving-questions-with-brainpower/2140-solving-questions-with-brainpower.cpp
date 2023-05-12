class Solution {
public:
    long long dp[500005];
    int n;
    long long solve(int idx,vector<vector<int>>& questions){
        if(idx>=n)return 0;
        long long &ret = dp[idx];
        if(~ret)return ret;
        ret=max(ret,solve(idx+questions[idx][1]+1,questions)+questions[idx][0]);

        ret=max(ret,solve(idx+1,questions));
        return ret;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof dp);
        n = questions.size();
        return solve(0,questions);
    }
};