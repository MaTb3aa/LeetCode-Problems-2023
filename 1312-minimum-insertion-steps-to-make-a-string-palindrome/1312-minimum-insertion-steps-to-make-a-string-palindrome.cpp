class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,string &s){
        if(i>=j)return 0;
        int &ret = dp[i][j];
        if(~ret)return ret;
        ret = 1e9;
        if(s[i]==s[j])
            ret=min(ret,solve(i+1,j-1,s));
        ret=min(ret,solve(i+1,j,s)+1);
        ret=min(ret,solve(i,j-1,s)+1);
        return ret;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof dp);
        return solve(0,s.size()-1,s);
    }
};