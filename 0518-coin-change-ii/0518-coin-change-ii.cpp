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
        vector<vector<long long>>dp(n,vector<long long>(amount+1,0));
        
        for(int i=0;i<=amount;i++){
            dp[0][i]=i%coins[0]==0;
        }

        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++){
                int notTake =dp[ind-1][t];
                int take=0;
                if(t>=coins[ind]){
                    take = dp[ind][t-coins[ind]];
                }
                dp[ind][t]=(long long)take+notTake;
            }
        }

        return dp[n-1][amount];
    }
};