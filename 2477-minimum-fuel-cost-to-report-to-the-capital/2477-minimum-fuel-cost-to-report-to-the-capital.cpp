class Solution {
public:
    vector<vector<int>>g;
    long long foul;
    int dfs(int node,int par,int &seats){
        int representatives = 1 ;
        for(int child : g[node]){
            if(child != par)
                representatives+=dfs(child,node,seats);
        }
        if(node){
            foul+=(representatives+seats-1)/seats;
        }
        return representatives;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        g = vector<vector<int>>(n+1);
        for(int i=0;i<n;i++){
            g[roads[i][0]].push_back(roads[i][1]);
            g[roads[i][1]].push_back(roads[i][0]);
        }
        dfs(0,-1,seats);
        return  foul;
      
       
    }
};