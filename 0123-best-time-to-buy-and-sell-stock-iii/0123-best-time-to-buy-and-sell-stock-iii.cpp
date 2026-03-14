class Solution {
public:
    int f(int i,int buy,vector<int>& prices,int n,int count,vector<vector<vector<int>>>& dp){
        if(i==n||count==0) return 0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        int profit=0;
        if(buy){
            profit+=max(-prices[i]+f(i+1,0,prices,n,count,dp),f(i+1,1,prices,n,count,dp));
        }
        else if(!buy&&count<4){
            profit+=max(prices[i]+f(i+1,1,prices,n,count-1,dp),f(i+1,0,prices,n,count,dp));
        }
        return dp[i][buy][count]=profit;
    }
    int maxProfit(vector<int>& prices) { 
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,prices,n,2,dp);
    }
};