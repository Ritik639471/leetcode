class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n+2,0),dp1(n+2,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=max({-prices[i]+dp1[i+1],dp[i+1]});
            dp1[i]=max({prices[i]+dp[i+2],dp1[i+1]});
        }
        return dp[0];
    }
};