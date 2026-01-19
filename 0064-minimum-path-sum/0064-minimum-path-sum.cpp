class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>temp(m,0);
        for(int i=0;i<n;i++){
            vector<int>dp(m,0);
            for(int j=0;j<m;j++){
                if(i==0&&j==0) dp[0]=grid[0][0];
                else{
                int up=grid[i][j];
                if(i>0) up+=temp[j];
                else up+=1e9;
                int left=grid[i][j];
                if(j>0) left+=dp[j-1];
                else left+=1e9;

                dp[j]=min(up,left);
                }
            }
            temp=dp;
        }
        
        return temp[m-1];
    }
};