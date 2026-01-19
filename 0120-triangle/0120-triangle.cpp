class Solution {
public:
    int func(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        if(i+1==triangle.size()) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int down = triangle[i][j]+func(triangle,i+1,j,dp);
        int right = triangle[i][j]+func(triangle,i+1,j+1,dp);
        return dp[i][j]=min(down,right);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        vector<int>front(n,0),curr(n,0);

        for(int j=0;j<triangle.size();j++) front[j]=triangle[n-1][j];

        for(int i=n-2;i>=0;i--){

            for(int j=i;j>=0;j--){
                int down = triangle[i][j]+front[j];
                int right = triangle[i][j]+front[j+1];
                curr[j]=min(down,right);
            }
            front=curr;
        }
        return front[0];
    }
};