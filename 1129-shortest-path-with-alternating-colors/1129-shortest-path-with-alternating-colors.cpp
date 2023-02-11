class Solution {
public:
   
      
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,bool>>>g(n);
        
        for(auto t : redEdges)
           g[t[0]].push_back({t[1],0}); 
        for(auto t : blueEdges)
           g[t[0]].push_back({t[1],1}); 
        
        
        //BFS
        vector<vector<int>>vis(n,vector<int>(2));
        vis[0][0] = vis[0][1] = true;
        vector<int>dist(n,-1);
        dist[0]=0;
        // node dist color 
        queue<tuple<int,int,int>>q;
        q.push({0,0,-1});
        
        while(q.size()){
            auto [curNode,path,curColor] = q.front();
            q.pop();
            for(auto [childNode,childColor] : g[curNode]){
                
                if(curColor != childColor && !vis[childNode][childColor]){
                    if(dist[childNode]==-1) dist[childNode] = path+1;
                    q.push({childNode,path+1,childColor});
                    vis[childNode][childColor]=1;
                }
            }
        }
        return dist;
        
      
    }
};