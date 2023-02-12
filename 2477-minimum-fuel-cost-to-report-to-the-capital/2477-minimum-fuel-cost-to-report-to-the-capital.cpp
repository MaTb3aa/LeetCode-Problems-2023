class Solution {
public:
    vector<vector<int>>g;
    long long n,ans=0;
    long long solve(int node,int par,int &seats){
        long long ret = 0;
        
        for(auto child : g[node])
            if(child!=par)
                ret += 1 + solve(child,node,seats);
            
        if(par!=-1 )ans+=(ret+seats)/seats;
        
        return ret;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        n = roads.size();
        g = vector<vector<int>>(n+1);
        for(int i=0;i<n;i++){
            g[roads[i][0]].push_back(roads[i][1]);
            g[roads[i][1]].push_back(roads[i][0]);
        }
        solve(0,-1,seats);
        return  ans;
      
       
    }
};