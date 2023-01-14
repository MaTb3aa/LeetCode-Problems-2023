class Solution {
public:
    vector<vector<int>>adj;
    int n,mx;
    int dfs(int u,int p,int &len, string &s){
        int longestChain = 0 ;
        int secondLongestChain = 0;
        
        for(auto child : adj[u]){
            int longestChainFromChild = dfs(child,u,len,s);
            if(s[u] == s[child])continue;
            if(longestChainFromChild > longestChain){
                secondLongestChain = longestChain;
                longestChain = longestChainFromChild;
            }
            else if(longestChainFromChild > secondLongestChain){
                secondLongestChain =longestChainFromChild;
            }
        }
        len = max(len, longestChain+secondLongestChain+1);
        return longestChain+1;
    }
    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        adj = vector<vector<int>>(n);
        
        for(int i = 1 ; i < n; i++){
            adj[parent[i]].push_back(i);
        }
        int len = 1;
        dfs(0,-1,len,s);
        return len;
    }
};