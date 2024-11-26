class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // maxProfit[k][i] = max profit using at most k transactions up to day i
        int maxTx = 1000;
        vector<vector<int>> dp(maxTx + 1, vector<int>(n, 0));

        // Fill DP table
        for (int k = 1; k <= maxTx; ++k) {
            int maxDiff = -prices[0]; // Max difference encountered so far
            for (int i = 1; i < n; ++i) {
                dp[k][i] = max(dp[k][i - 1], prices[i] + maxDiff); // Skip or sell today
                maxDiff = max(maxDiff, dp[k - 1][i] - prices[i]);   // Update maxDiff
            }
        }

        return dp[maxTx][n - 1];
    }
};
