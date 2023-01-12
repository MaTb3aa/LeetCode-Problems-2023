class Solution {
public:
    vector<vector<int>>adj;
    vector<int>ans;
   
    vector<int> dfs(int u,int p,string &labels){
        vector<int>nodeCount(26);
        nodeCount[labels[u]-'a']++;
        for(auto child : adj[u]){
            if(child != p){
                vector<int>childCount = dfs(child,u,labels);
                for(int i=0;i<26;i++){
                    nodeCount[i]+=childCount[i];
                }
            }
        }
        ans[u] = nodeCount[labels[u]-'a'];
        return nodeCount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj = vector<vector<int>>(n);
        ans = vector<int>(n);
        
        for(auto t : edges){
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        
        dfs(0,-1,labels);
        return ans;
    }
};