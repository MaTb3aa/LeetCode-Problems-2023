class Solution {
public:
    int n;
    vector<vector<int>>g;
    vector<int>BFS(int node){
        vector<int>dist(n,-1);
        queue<int>q;
        q.push(node);
        dist[node]=0;
        while(q.size()){
            int cur = q.front();q.pop();
            for(auto ch : g[cur]){
                if(dist[ch]==-1){
                    dist[ch] = dist[cur]+1;
                    q.push(ch);
                }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        g = vector<vector<int>>(n);
        for(int i = 0 ; i < n ;i++){
            if(~edges[i])
                g[i].push_back(edges[i]);
        }
        vector<int>d1 = BFS(node1);
        vector<int>d2 = BFS(node2);
        int dist = 1e9,node=-1;
        for(int i = 0 ; i< n ;i++){
            if(~d1[i] && ~d2[i] &&max(d1[i],d2[i]) < dist )
                dist = max(d1[i],d2[i]), node = i;
        }
        return node;
        
        
    }
};