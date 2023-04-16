class Solution {
public:
    int n,m,sz;
    vector<vector<int>>freq;
    const int mod = 1e9+7;
    int dp[1001][1001];
    int solve(int i,int k,vector<string>& words, string& target){
        if(i==n)return 1;
        if(k==m)return 0;
        
        int &ret = dp[i][k];
        if(~ret)return ret;
        ret = 0 ;
        ret += solve(i,k+1,words,target)%mod;
        
        char ch = target[i];
        
        int cnt = freq[k][ch-'a'];
        if(cnt>0)
            ret += (((1LL * cnt)) * (solve(i+1,k+1,words,target)))%mod;
        
        return ret%mod;
        
    }
    
    int numWays(vector<string>& words, string target) {
        n = target.size(); // string 
        m = words[0].size();   //string
        int sz = words.size();
        
        freq = vector<vector<int>>(m,vector<int>(26));
        
        for(auto word : words){
            for(int i = 0 ; i < word.size();i++){
                freq[i][word[i]-'a']++;
            }
        }
        memset(dp,-1,sizeof dp);
        return solve(0,0,words,target);
    }
};