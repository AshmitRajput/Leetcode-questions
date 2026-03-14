class Solution {
public:
    int f(int i,int buy,vector<int>& prices,int n,int count,vector<vector<vector<int>>>& dp){
        if(i==n||count==0) return 0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,0,prices,n,count,dp),f(i+1,1,prices,n,count,dp));
        }
        else{
            profit=max(prices[i]+f(i+1,1,prices,n,count-1,dp),f(i+1,0,prices,n,count,dp));
        }
        return dp[i][buy][count]=profit;
    }
    int maxProfit(vector<int>& prices) { 
        int n=prices.size();
        int count=2;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int count=1;count<3;count++){
                    if(buy){
                        dp[i][buy][count]=max(-prices[i]+dp[i+1][0][count],dp[i+1][1][count]);
                    }
                    else{
                        dp[i][buy][count]=max(prices[i]+dp[i+1][1][count-1],dp[i+1][0][count]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};