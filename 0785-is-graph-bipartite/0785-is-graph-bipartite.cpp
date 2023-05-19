class Solution {
public:
    vector<vector<int>>g;
    vector<int>vis;
    int n;
    bool ans = 1;
    void dfs(int u,bool col){
        vis[u] = col;
        for(auto ch : g[u]){
            if(vis[ch] == -1){
                dfs(ch,!col);
            }   
            else if(vis[ch]==vis[u]) {
                ans = 0 ;return ;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vis = vector<int>(n,-1);
        g = vector<vector<int>>(n);
        for(int i = 0 ; i < n ;i++){
            for(auto t : graph[i])
                    g[i].push_back(t),g[t].push_back(i);
        }
        for(int i = 0 ; i < n ; i++){
            if(vis[i]==-1)dfs(i,0);
        }
        return ans;
        
        
        
    }
};