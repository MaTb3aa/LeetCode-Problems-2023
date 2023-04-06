class Solution {
public:
    int n,m;
    int vis [101][101];

    bool valid(int x,int y){
        return x>=0 && y>= 0 && x<n && y <m;
    }
    bool solve(int x,int y,vector<vector<int>>& grid){
        if(!valid(x,y))return 0;
        
        if(grid[x][y]||vis[x][y])return 1;
        vis[x][y]=1;
        int ret = 1;
        ret&=solve(x+1,y,grid);
        ret&=solve(x-1,y,grid);
        ret&=solve(x,y+1,grid);
        ret&=solve(x,y-1,grid);
        return ret;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j= 0 ; j < m; j++ ){
                if(!vis[i][j]&&!grid[i][j]){
                    cnt+=solve(i,j,grid);
                    
                }
            }
        }
        return cnt;
        
    }
};