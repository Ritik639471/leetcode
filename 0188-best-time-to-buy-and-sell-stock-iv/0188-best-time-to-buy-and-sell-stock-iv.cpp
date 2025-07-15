class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int l = 1; l <= k; l++) {
            for (int i = n - 2; i >= 0; i--) {
                dp[i][l] = dp[i + 1][l];
                for (int j = i + 1; j < n; j++) {
                    dp[i][l] = max(
                        {dp[i][l], prices[j] - prices[i] + dp[j + 1][l - 1]});
                }
            }
        }
        return dp[0][k];
    }
};