class Solution {
public:
    
    int find(int u,vector<int>&par){
        if(par[u]==u)return u;
        return par[u] = find(par[u],par);
    }
    void join(int a,int b,vector<int>&par){
        a = find(a,par);
        b = find(b,par);
        if(a!=b){
            par[a]=b;
        }
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>par(n+1);
        for(auto t : trust)par[t[1]]+=t[0];
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(par[i]+i == n*(n+1) /2 )ans= i;
        }
         for(auto t : trust)if(t[0]==ans)return -1;
        return ans;

        
    }
};