class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2*k+1, 0));
        for (int l = 1; l <= 2*k; l++) {
            for (int i = n - 1; i >= 0; i--) {
                if(l%2==0){
                    dp[i][l]=max(dp[i+1][l],-prices[i]+dp[i+1][l-1]);
                }
                else{
                    dp[i][l]=max(dp[i+1][l],prices[i]+dp[i+1][l-1]);
                }
            }
        }
        return dp[0][2*k];
    }
};