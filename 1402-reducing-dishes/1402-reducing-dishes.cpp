class Solution {
public:
    long long dp[505][505];
    int n;
    long long solve(int idx,int cnt,vector<int>& satisfaction){
        if(idx==n)return 0;
        long long &ret=dp[idx][cnt];
        if(~ret)return ret;
        ret=max(ret,solve(idx+1,cnt+1,satisfaction)+satisfaction[idx]*cnt);
        ret=max(ret,solve(idx+1,cnt,satisfaction));
        return ret;

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof dp);
        return solve(0,1,satisfaction);
    }
};