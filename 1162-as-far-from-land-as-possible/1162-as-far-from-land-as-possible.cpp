class Solution {
public:
    int n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    bool valid(int x,int y){
        return x>=0 && y>=0 && x<n && y<n;
    }
    int BFS(vector<vector<int>>& grid){
        vector<vector<int>>dist(n,vector<int>(n,0x3f3f3f3f));
        queue<pair<int,int>>q;
        
        for(int i = 0 ; i < n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]){
                    q.push({i,j});
                    dist[i][j]=0;
                }
        int ans=-1;
        
        while(q.size()){
            auto [a,b] = q.front();q.pop();
            for(int i=0;i<4;i++){
                int ddx=dx[i]+a;
                int ddy=dy[i]+b;
                if(!valid(ddx,ddy))continue;
                if(!grid[ddx][ddy] && dist[ddx][ddy] > dist[a][b]+1){
                    dist[ddx][ddy]=dist[a][b]+1;
                    q.push({ddx,ddy});
                    ans=max(ans,dist[a][b]+1); 
                }
            }
        }
      
        return ans;
    }
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        
        return BFS(grid);
                
            
        
    }
};