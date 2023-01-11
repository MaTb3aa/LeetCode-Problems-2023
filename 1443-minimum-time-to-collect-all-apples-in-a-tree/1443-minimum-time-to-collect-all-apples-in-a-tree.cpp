class Solution {
public:
    vector<vector<int>>adj;
    int dfs(int node,int par,vector<bool>& hasApple){
        int totalTime = 0;
        int childTime =0;
        for(auto child : adj[node]){
            if(child != par){
                childTime = dfs(child,node,hasApple);
                if(childTime || hasApple[child])
                totalTime+=childTime+2;
                
            }
        }
        return totalTime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj = vector<vector<int>>(n);
        for(auto t : edges){
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        return dfs(0,-1,hasApple);
    }
};