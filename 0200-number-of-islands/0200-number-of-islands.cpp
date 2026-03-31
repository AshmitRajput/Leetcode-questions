class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<char>>& vis,int n, int m){
        vis[x][y]='1';
        int delx[]={-1,0,1,0};
        int dely[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+delx[i];
            int ny=y+dely[i];
            if(nx<n&&nx>=0&&ny<m&&ny>=0&&vis[nx][ny]!='1'&&grid[nx][ny]=='1') dfs(nx,ny,grid,vis,n,m);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<char>>vis(n,vector<char>(m,'0'));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis==grid) break;
                if(grid[i][j]=='1' && vis[i][j]=='0'){
                    count++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return count;
    }
};