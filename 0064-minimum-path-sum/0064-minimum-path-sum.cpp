class Solution {
public:
    int n,m;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1)return grid[i][j];
        if(i>=n || j>=m)return 1e9;
        int &ret = dp[i][j];
        if(~ret)return ret;
        ret = 1e9;
        ret=min(ret,solve(i+1,j,grid)+grid[i][j]);
        ret=min(ret,solve(i,j+1,grid)+grid[i][j]);
        return ret;
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof dp);
        return solve(0,0,grid);
    }
};