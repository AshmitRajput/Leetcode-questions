class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> dp;
    int f(vector<int>& coins, int ind, int target) {
        if (target == 0) return 0;
        if (ind < 0) return INF;
        if (dp[ind][target] != -1) return dp[ind][target];

        int notTake = f(coins, ind - 1, target);
        int take = INF;

        if (coins[ind] <= target) {
            take = 1 + f(coins, ind, target - coins[ind]);
        }

        return dp[ind][target] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));
        int ans = f(coins, n - 1, amount);
        return (ans >= INF ? -1 : ans);
    }
};