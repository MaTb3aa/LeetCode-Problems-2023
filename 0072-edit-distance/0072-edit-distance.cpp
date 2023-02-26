class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,string& a, string& b){
        if(i==a.size()) return b.size() - j;
        if(j== b.size())return a.size() - i;
        
        int &ret = dp[i][j];
        if(~ret)return ret;
        ret = 1e9;
        if(a[i]==b[j])
            ret = min(ret,solve(i+1,j+1,a,b));
        
      
        ret=min(ret,solve(i+1,j,a,b)+1);
        ret=min(ret,solve(i,j+1,a,b)+1);
        ret=min(ret,solve(i+1,j+1,a,b)+1);

        return ret;

    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,word1,word2);
        
    }
};