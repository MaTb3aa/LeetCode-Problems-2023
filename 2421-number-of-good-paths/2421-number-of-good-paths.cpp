class Solution {
public:
    int par[100005];
    int find(int u){
        if(par[u]==u)return u;
        return par[u] = find(par[u]);
    }
    void join(int u,int v){
        u = find(u);
        v = find(v);
        if(u!=v){
            par[u] = v;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        int n = vals.size();
        vector<vector<int>>adj(n);
        
        for(auto t : edges){
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        
        for(int i=0;i<n;i++){
            mp[vals[i]].push_back(i);
            par[i]=i;
        }
        int ans =0 ;
        for(auto& [value,nodes] : mp){
            
            for(int node : nodes){
                for(int child : adj[node]){
                    if(vals[node] >= vals[child]){
                        join(node,child);
                    }
                }
            }
            
            map<int,int>freq;
            for(auto node : nodes)freq[find(node)]++;
            
            for(auto &[_,cnt] : freq){
                ans+=(cnt*(cnt+1))/2;
            }
        }
        return ans;

       
      
        
        
    }
};