class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=i+2;j++){
                if(i+j>n) break;
                dp[i]=min(dp[i],dp[i+j]);
            }
            dp[i]+=prices[i];
        }
        return dp[0];
    }
};