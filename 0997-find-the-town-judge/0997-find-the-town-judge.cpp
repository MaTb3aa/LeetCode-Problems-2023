class Solution {
public:
    
  
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>par(n+1);
        for(auto t : trust)par[t[1]]+=t[0];
        int ans = -1 , sum =n*(n+1) /2;
        for(int i=1;i<=n;i++){
            if(par[i]+i == sum)ans= i;
        }
         for(auto t : trust)if(t[0]==ans)return -1;
        return ans;

        
    }
};