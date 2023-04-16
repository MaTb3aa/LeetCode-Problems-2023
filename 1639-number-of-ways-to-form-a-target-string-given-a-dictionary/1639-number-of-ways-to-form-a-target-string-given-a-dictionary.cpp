class Solution {
public:
    int n,m,sz;
    int dp[1001][1001];
    vector<vector<int>>freq;
    const int mod = 1e9+7;
    int solve(int i,int k,vector<string>& words, string& target){
        if(i==n)return 1;
        if(k==m)return 0;
        int &ret = dp[i][k];
        if(~ret)return ret;
        ret = 0 ;
        ret += solve(i,k+1,words,target)%mod;
        int cnt = freq[k][target[i]-'a'];
        if (cnt) 
            ret+=(1LL*solve(i+1,k+1,words,target)*cnt)%mod;
        return ret%mod;
    }
    int numWays(vector<string>& words, string target) {
        n = target.size();
        m = words[0].size();
        sz = words.size();
        freq = vector<vector<int>>(m,vector<int>(26));

        for(auto word : words){
            for(int k = 0 ; k  < m ; k++)
                freq[k][word[k]-'a']++;
        }

        memset(dp,-1,sizeof dp);
        return solve(0,0,words,target);
    }
};