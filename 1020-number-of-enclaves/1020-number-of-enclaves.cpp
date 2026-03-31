class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>&vis, int n,int m){
        vis[x][y]=1;
        int delx[]={-1,0,1,0}; int dely[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+delx[i],ny=y+dely[i];
            if(nx<n&&nx>=0&&ny<m&&ny>=0 && vis[nx][ny]!=1 && grid[nx][ny]==1){
                dfs(nx,ny,grid,vis,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(grid[0][j]==1) dfs(0,j,grid,vis,n,m);
        }
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1) dfs(n-1,j,grid,vis,n,m);
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1) dfs(i,m-1,grid,vis,n,m);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(i,0,grid,vis,n,m);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0) count++;
            }
        }
        return count;
    }
};