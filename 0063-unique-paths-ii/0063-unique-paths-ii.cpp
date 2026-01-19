class Solution {
public:
    int func(vector<vector<int>>& grid,vector<vector<int>>& dp,int n,int m){
        if(n==0&&m==0&&grid[n][m]!=1) return 1;
        if(n<0||m<0) return 0;
        if(grid[n][m]==1) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int up=func(grid,dp,n-1,m);
        int left=func(grid,dp,n,m-1);

        return dp[n][m]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(obstacleGrid,dp,n-1,m-1);
    }
};