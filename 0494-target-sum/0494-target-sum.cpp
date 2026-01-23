class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int mod = 1e9 + 7;
        int n = nums.size();

        int totalSum = 0;
        for (int x : nums) totalSum += x;
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0)
            return 0;

        int s1 = (target + totalSum) / 2;
 
        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j] +
                                dp[i - 1][j - nums[i - 1]]) % mod;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][s1];
    }
};