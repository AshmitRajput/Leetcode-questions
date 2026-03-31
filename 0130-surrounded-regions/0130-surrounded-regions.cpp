class Solution {
public:
    void dfs(int x,int y, vector<vector<char>>& board, vector<vector<char>>& vis,int n,int m){
        vis[x][y]='O';
        int delx[]={-1,0,1,0}; int dely[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+delx[i],ny=y+dely[i];
            if(nx<n&&nx>=0&&ny<m&&ny>=0 && vis[nx][ny]!='O' && board[nx][ny]=='O'){
                dfs(nx,ny,board,vis,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<char>>vis(n,vector<char>(m,'X'));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(0,j,board,vis,n,m);
        }
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O') dfs(n-1,j,board,vis,n,m);
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O') dfs(i,m-1,board,vis,n,m);
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(i,0,board,vis,n,m);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=vis[i][j];
            }
        }


    }
};