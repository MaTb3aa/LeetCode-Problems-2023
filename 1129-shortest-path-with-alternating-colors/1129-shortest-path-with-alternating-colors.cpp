class Solution {
public:
    enum {red,blue};
    vector<vector<pair<int,int>>>g;
    int BFS(int &n,int node,bool color){
        queue<pair<int,bool>>q;
        q.push({node,color});
        vector<vector<int>>dist(n,vector<int>(2,0x3f3f3f3f));
        dist[node][0]=0;
        dist[node][1]=0;
        while(q.size()){
            auto cur = q.front();q.pop();
            if(!cur.first)return min(dist[cur.first][0],dist[cur.first][1]);
            for(auto child : g[cur.first]){
                if(cur.second != child.second && dist[child.first][child.second] > dist[cur.first][cur.second]+1){
                    dist[child.first][child.second] = dist[cur.first][cur.second]+1;
                    q.push(child);
                }
            }
        }
        return 0x3f3f3f3f;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        g = vector<vector<pair<int,int>>>(n);
        for(auto t : redEdges)
            g[t[1]].push_back({t[0],red});
        
        for(auto t : blueEdges)
            g[t[1]].push_back({t[0],blue});
        
        vector<int>ans(n);
        
        for(int i=1;i<n;i++){
            ans[i] = min(BFS(n,i,0),BFS(n,i,1));
            if(ans[i]==0x3f3f3f3f)ans[i] = -1;
        }
        return ans;
    }
};