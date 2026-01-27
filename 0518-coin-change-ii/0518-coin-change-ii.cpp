class Solution {
public:
    int f(vector<int>& coins,int target,int ind,vector<vector<int>>& dp){
        if (ind==0) return target%coins[0]==0;
        if (dp[ind][target]!=-1) return dp[ind][target];

        int notTake =f(coins,target,ind-1,dp);
        int take=0;
        if(target>=coins[ind]){
            take = f(coins,target-coins[ind],ind,dp);
        }

        return dp[ind][target]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(coins,amount,n-1,dp);
    }
};