class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(int i, int j,string &s){
        if(i>j)return 0;
        if(i==j)return 1;
        int &ret =dp[i][j];
        if(~ret)return ret;
        if(s[i]==s[j])
            ret = max(ret,solve(i+1,j-1,s)+2);
        ret=max(ret,solve(i+1,j,s));
        ret=max(ret,solve(i,j-1,s));
        return ret;
    }
    int longestPalindromeSubseq(string s) {
        n = s.size();
        memset(dp,-1,sizeof dp);
        return solve(0,n-1,s);
    }
};