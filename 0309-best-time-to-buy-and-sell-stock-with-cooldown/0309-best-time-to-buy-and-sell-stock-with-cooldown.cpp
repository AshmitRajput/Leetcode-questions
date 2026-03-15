class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=n/2;
        vector<vector<vector<int>>>dp(n+2,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int count=1;count<k+1;count++){
                    if(buy){
                        dp[i][buy][count]=max(-prices[i]+dp[i+1][0][count],dp[i+1][1][count]);
                    }
                    else{
                        dp[i][buy][count]=max(prices[i]+dp[i+2][1][count-1],dp[i+1][0][count]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};