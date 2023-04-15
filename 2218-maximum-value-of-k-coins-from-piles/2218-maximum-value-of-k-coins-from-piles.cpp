class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int idx,int rem,vector<vector<int>>& piles){
        if(!rem||idx==n)return 0;
       
        int &ret=dp[idx][rem];
        if(~ret)return ret;
      
       ret=max(ret,solve(idx+1,rem,piles));
        
       for(int j=0;j<min(rem,(int)piles[idx].size());j++)
           ret=max(ret,solve(idx+1,rem-j-1,piles)+piles[idx][j]);
       
        return ret;
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < piles[i].size() ; j++)
                piles[i][j]+=piles[i][j-1];
        }
        dp = vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return solve(0,k,piles);
    }
};