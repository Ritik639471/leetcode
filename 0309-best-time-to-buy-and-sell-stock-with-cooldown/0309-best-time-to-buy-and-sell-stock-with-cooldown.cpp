class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        vector<int>dp(n+2,0),dp1;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i]=max({-prices[i]+prices[j]+dp[j+2],dp[i+1],dp[i]});
            }
        }
        return dp[0];
    }
};